#include "fetch/Fetcher.hpp"
#include "html/ParserDom.h"
#include "utilities/HelperFunctions.hpp"

#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace htmlcxx;


Fetcher::Fetcher(const std::string &path,
		 const std::string &filename_input,
		 const std::string &filename_output)
  : m_Path(path),
    m_FilenameInput(path + filename_input),
    m_FilenameOutput(path + filename_output)
{ }



Fetcher::~Fetcher()
{
   curl_easy_cleanup(m_Curl);
}



// Could not make this a member method of Fetcher.
// Solution for now: put it out.
std::size_t
writeData(char *ptr, 
	  std::size_t size, 
	  std::size_t nmemb, 
	  void *userdata)
{
  std::ostringstream *stream = (std::ostringstream*)userdata;
  size_t count = size * nmemb;
  stream->write(ptr, count);
  return count;
}



std::string
Fetcher::fetchSingle(const std::string &url)
{
  std::string ret = "";

  m_Curl = curl_easy_init();

  assert (m_Curl);

  std::ostringstream stream;
  
  curl_easy_setopt(m_Curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(m_Curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(m_Curl, CURLOPT_WRITEFUNCTION, writeData);
  curl_easy_setopt(m_Curl, CURLOPT_WRITEDATA, &stream);

  std::cerr << "Fetching from " << url << std::endl;
  m_Res = curl_easy_perform(m_Curl);
      
  if (m_Res != CURLE_OK)
    { 
      std::cerr << "FAILED!" << std::endl;
    }
  else
    {
      std::cerr << "SUCCEEDED." << std::endl;
      ret = stream.str();
    }

  return ret;
}




bool
Fetcher::getDeadlineTitleURL(std::ifstream& file_input,
			     std::string &deadline,
			     std::string &title,
			     std::string &url)
{
  deadline = "";
  title    = "";
  url      = "";

  std::getline(file_input, deadline);
  if (deadline == "") return false;

  // only accept deadline of the form YYYYMMDD
  if (deadline.length() == 8)
    {
      std::getline(file_input, title);
    }
  else
    {
      title = deadline;
      deadline = "";
    }

  if (title.find("http://") == std::string::npos)
    {
      std::getline(file_input, url);
      if (url == "") return false;
    }
  else
    {
      url = title;
      title = "";
    }

  return true;
}




// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string 
Fetcher::currentDateTime() 
{
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);

  strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct);
  
  return buf;
}



void
Fetcher::fetchMultiple()
{
  std::ifstream file_input(m_FilenameInput.c_str());
  std::ofstream file_output(m_FilenameOutput.c_str());

  if (!file_input.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameInput << "\" for reading!" << std::endl;
      return;
    }

  if (!file_output.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameOutput << "\" for writing!" << std::endl;
      return;
    }

  const std::string now = currentDateTime();

  std::size_t count = 0;
  std::ostringstream count_str;

  while (file_input.good())
    {
      std::string deadline;
      std::string title;
      std::string url;
      if (!getDeadlineTitleURL(file_input, deadline, title, url)) break;

      std::string html_code = fetchSingle(url);

      count_str.str("");
      count_str << count++;

      std::string filename_scholarship = m_Path + now + count_str.str() + ".txt";
      std::ofstream file_scholarship(filename_scholarship.c_str());
      
      if (!file_scholarship.is_open())
	{
	  std::cerr << "Cannot open file \"" << filename_scholarship << "\" for writing!" << std::endl;
	}
      else
	{
	  file_scholarship << html_code;
	  file_scholarship.close();
	      

	  file_output << "__BEGIN_____" << std::endl;
	  if (deadline != "")
	    file_output << "__DEADLINE__=" << deadline << std::endl;

	  if (title != "")
	    file_output << "__TITLE_____=" << title << std::endl;

	  file_output << "__FILENAME__=" << filename_scholarship << std::endl;
	  file_output << "__URL_______=" << url << std::endl;
	  file_output << "__END_______" << std::endl;
	}
    }

  file_input.close();
  file_output.close();
}



void
Fetcher::fetchDbworld()
{
  std::string dbworld = fetchSingle("https://research.cs.wisc.edu/dbworld/browse.html");
  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(dbworld);
  
  for (tree<HTML::Node>::iterator table_it = dom.begin(); table_it != dom.end(); ++table_it)
    {
      if (table_it->tagName() == "TABLE")
	{
	  tree<HTML::Node>::iterator beg_table = table_it.begin();
	  tree<HTML::Node>::iterator end_table = table_it.end();

	  // Table structure:
	  // - (0) Sent (upload date)
	  // + (1) Message Type
	  // - (2) From
	  // + (3) Subject
	  // + (4) Deadline
	  // + (5) Web Page

	  bool is_head = true;
	  int c = 0;
	  for (tree<HTML::Node>::iterator row_it = beg_table; row_it != end_table; ++row_it)
	    {
	      if (row_it->tagName() == "TR")
		{
		  if (is_head) is_head = false;
		  else
		    {
		      // at a row with content
		      tree<HTML::Node>::iterator beg_row = row_it.begin();
		      tree<HTML::Node>::iterator end_row = row_it.end();

		      std::size_t index = 0;
		      bool move_on = 0;

		      std::string type = "";
		      std::string title = "";
		      std::string url = "";
		      std::string deadline = "";
		      std::string website = "";

		      for (tree<HTML::Node>::iterator column_it = beg_row; column_it  != end_row; column_it++)
			{
			  if (column_it->tagName() == "TD")
			    {		
			      move_on = 1;
			      switch (index++)
				{
				case 1: // type: journal CFP | conf. ann. | ***job ann.*** | news | soft. ann.
				  {
				    type = column_it->content(dbworld);
				    if (type != "job ann. ") move_on = -1;
				    break;
				  }
				case 3:
				  {
				    tree<HTML::Node>::iterator url_it = column_it.begin();
				    url = url_it->text();
				    extractLink(url);
				    title = url_it->content(dbworld);
				    break;
				  }
				case 4:
				  {
				    deadline = column_it->content(dbworld);
				    boost::gregorian::date d(boost::gregorian::from_uk_string(deadline));
				    deadline = boost::gregorian::to_iso_string(d);
				    break;
				  }
				case 5:
				  {
				    tree<HTML::Node>::iterator link_it = column_it.begin();
				    website = link_it->text();
				    extractLink(website);
				    break;
				  }
				}

			      if (move_on == -1) break;
			    }
			}

		      if (move_on == 1) // write to file
			{
			}

		      c++;
		      if (c == 15) break;
		    }
		}
	    }
	  break;
	}
    }
}
