#include "fetch/Fetcher.hpp"
#include "utilities/ConstantStrings.hpp"
#include "utilities/DateConverter.hpp"
#include "utilities/DateType.hpp"
#include "utilities/HelperFunctions.hpp"
#include "utilities/Logger.hpp"

#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace htmlcxx;


Fetcher::Fetcher(const std::string &path,
		 const std::string &pathDatabase,
		 const std::string &filename_input,
		 const std::string &filename_output,
		 const std::string &filename_marker_dbworld,
		 const std::string &filename_input_dbworld,
                 const std::string &filename_html_scholarship_positions_gmail,
                 const std::string &filename_input_scholarship_positions_gmail)
  : m_Path(path),
    m_FilenameInput(path + filename_input),
    m_FilenameOutput(path + filename_output),
    m_FilenameMarkerDbworld(pathDatabase + filename_marker_dbworld),
    m_FilenameInputDbworld(path + filename_input_dbworld),
    m_FilenameHtmlScholarshipPositionsGmail(path + filename_html_scholarship_positions_gmail),
    m_FilenameInputScholarshipPositionsGmail(path + filename_input_scholarship_positions_gmail)
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
  DBGDEBUG("Fetching from " << url)

  std::string ret = "";

  m_Curl = curl_easy_init();

  assert (m_Curl);

  std::ostringstream stream;
  
  curl_easy_setopt(m_Curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(m_Curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(m_Curl, CURLOPT_WRITEFUNCTION, writeData);
  curl_easy_setopt(m_Curl, CURLOPT_WRITEDATA, &stream);

  m_Res = curl_easy_perform(m_Curl);
      
  if (m_Res != CURLE_OK)
    { 
      DBGDEBUG("FAILED!")
    }
  else
    {
      DBGDEBUG("SUCCEEDED.")
      ret = stream.str();
    }

  return ret;
}




bool
Fetcher::getInput(std::ifstream& file_input,
		  FetchedInfoScholarship &fis)
{
  std::string line = "";

  std::getline(file_input, line);
  if (line == "") return false;

  // only accept deadline of the form YYYYMMDD
  if (line.length() == 8)
    {
      fis.m_Deadline = line;
      std::getline(file_input, line);
      if (line == "") return false;
    }

  assert (line.find("http://") != std::string::npos);
  fis.m_URL = line;

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
  DBGDEBUG("Fetching from manual input...")

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

  ConstantStrings *constrings = ConstantStrings::instance();

  while (file_input.good())
    {
      FetchedInfoScholarship fis;
      if (!getInput(file_input, fis)) break;

      writeInputToManager(file_output, fis, now, count);
      count++;
    }

  DBGINFO("Fetched " << count << " scholarship items from manual input!")

  file_input.close();
  file_output.close();
}




FetchedInfoScholarship
Fetcher::lastCrawledDbworldJob()
{
  FetchedInfoScholarship result;

  std::ifstream file_marker_dbworld(m_FilenameMarkerDbworld.c_str());
  if (file_marker_dbworld.good())
    {
      ConstantStrings* constrings = ConstantStrings::instance();
      std::string line;
      std::getline(file_marker_dbworld, line);
      

      assert (line.compare(constrings->PrefixBegin) == 0);


      while (line != "" && line.compare(constrings->PrefixEnd) != 0)
	{
	  if (line.find(constrings->PrefixDeadline) != std::string::npos) result.m_Deadline = line.substr(constrings->PrefixDeadline.length());
	  if (line.find(constrings->PrefixTitle) != std::string::npos)    result.m_Title = line.substr(constrings->PrefixTitle.length());
	  if (line.find(constrings->PrefixURL) != std::string::npos)      result.m_URL = line.substr(constrings->PrefixURL.length());
	  if (line.find(constrings->PrefixWebpage) != std::string::npos)  result.m_Webpage = line.substr(constrings->PrefixWebpage.length());
	  std::getline(file_marker_dbworld, line);
	}

      file_marker_dbworld.close();
    }

  return result;
}



void
Fetcher::cacheCrawledDbworldJob(const FetchedInfoScholarship &fis)
{
  std::ofstream file_marker_dbworld(m_FilenameMarkerDbworld.c_str());
  if (file_marker_dbworld.is_open())
    {
      ConstantStrings* constrings = ConstantStrings::instance();
      file_marker_dbworld << constrings->PrefixBegin << std::endl 
			  << constrings->PrefixDeadline << fis.m_Deadline << std::endl
			  << constrings->PrefixTitle << fis.m_Title << std::endl
			  << constrings->PrefixURL << fis.m_URL << std::endl
			  << constrings->PrefixWebpage << fis.m_Webpage << std::endl
			  << constrings->PrefixEnd << std::endl;
      file_marker_dbworld.close();
    }
}



void
Fetcher::writeInputToManager(std::ofstream &file_input_to_manager,
			     FetchedInfoScholarship &fis,
			     const std::string &now,
			     const std::size_t count)
{
  ConstantStrings* constrings = ConstantStrings::instance();

  std::ostringstream count_str;
  count_str << count;

  std::string filename_scholarship = m_Path + now + count_str.str() + ".txt";
  std::ofstream file_scholarship(filename_scholarship.c_str());
  
  if (!file_scholarship.is_open())
    {
      std::cerr << "Cannot open file \"" << filename_scholarship << "\" for writing!" << std::endl;
    }
  else
    {
      fis.m_HTMLCode = fetchSingle(fis.m_URL);
      file_scholarship << fis.m_HTMLCode;
      file_scholarship.close();
      
      fis.m_Filename = filename_scholarship;

      file_input_to_manager << constrings->PrefixBegin    << std::endl;

      if (fis.m_Deadline != "") file_input_to_manager << constrings->PrefixDeadline << fis.m_Deadline << std::endl;
      if (fis.m_Title != "") file_input_to_manager << constrings->PrefixTitle << fis.m_Title << std::endl;

      file_input_to_manager << constrings->PrefixFilename << fis.m_Filename << std::endl;
      file_input_to_manager << constrings->PrefixURL << fis.m_URL << std::endl;

      if (fis.m_Webpage != "")	file_input_to_manager << constrings->PrefixWebpage << fis.m_Webpage << std::endl;

      file_input_to_manager << constrings->PrefixEnd << std::endl;
    }
}


int
Fetcher::fetchDbworldRow(const std::string &dbworld,
			 tree<HTML::Node>::iterator row_it,
			 FetchedInfoScholarship &fis)
{
  DBGDEBUG("Fetching from dbworld...")

  tree<HTML::Node>::iterator beg_row = row_it.begin();
  tree<HTML::Node>::iterator end_row = row_it.end();

  std::size_t index = 0;
  int move_on = 0;

  std::string type = "";

  for (tree<HTML::Node>::iterator column_it = beg_row; column_it  != end_row; column_it++)
    {
      if (column_it->tagName() == "TD")
	{		
	  move_on = 1; // found an entry
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
		fis.m_URL = url_it->text();
		extractLink(fis.m_URL);
		fis.m_Title = url_it->content(dbworld);
		break;
	      }
	    case 4:
	      {
		std::string deadline = column_it->content(dbworld);
		boost::gregorian::date d(boost::gregorian::from_uk_string(deadline));
		fis.m_Deadline = boost::gregorian::to_iso_string(d);
		break;
	      }
	    case 5:
	      {
		tree<HTML::Node>::iterator link_it = column_it.begin();
		fis.m_Webpage = link_it->text();
		extractLink(fis.m_Webpage);
		break;
	      }
	    }
	  
	  if (move_on == -1) // did NOT get a job announcement
	    break;
	}
    }

  return move_on;
}



void
Fetcher::fetchDbworld()
{
  const std::string now = "dbworld" + currentDateTime();
  std::size_t count = 0;

  std::string dbworld = fetchSingle("https://research.cs.wisc.edu/dbworld/browse.html");
  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(dbworld);

  FetchedInfoScholarship last_crawled_dbworld_job = lastCrawledDbworldJob();
  std::ofstream file_input_dbworld(m_FilenameInputDbworld.c_str());

  DBGDEBUG("Now exploring the table...")

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
	  for (tree<HTML::Node>::iterator row_it = beg_table; row_it != end_table; ++row_it)
	    {
	      if (row_it->tagName() == "TR")
		{
		  if (is_head) is_head = false;
		  else // at a row with content
		    {
		      FetchedInfoScholarship fis;
		      
		      int move_on = fetchDbworldRow(dbworld, row_it, fis);

		      if (move_on == 1) // write to file
			{
			  if (fis == last_crawled_dbworld_job) // check with the marker whether we reached last time's fetched data
			    {
			      DBGDEBUG("Encounter last time's crawled job. Bailing out...")
			      break; 
			    }

			  DBGDEBUG("Got a new job announcement")			 
			  if (++count == 1) cacheCrawledDbworldJob(fis);

			  writeInputToManager(file_input_dbworld, fis, now, count);			    
			}
		    }
		}
	    }
	  break;
	}
    }

  DBGINFO("Fetched " << count << " scholarship items from dbworld!")

  file_input_dbworld.close();
}



bool
Fetcher::isPotentialTitle(const std::string &s)
{
  return (s.find("Tags:") == std::string::npos && s.find("Apply Now") == std::string::npos && s != "&nbsp;");
}


void
Fetcher::fetchScholarshipPositionsGmail()
{
  const std::string now = "spgmail" + currentDateTime();
  std::size_t count = 0;
  
  std::ifstream file_input(m_FilenameHtmlScholarshipPositionsGmail.c_str());
  std::ofstream file_output(m_FilenameInputScholarshipPositionsGmail.c_str());

  if (!file_input.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameHtmlScholarshipPositionsGmail << "\" for reading!" << std::endl;
      return;
    }

  if (!file_output.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameInputScholarshipPositionsGmail << "\" for writing!" << std::endl;
      return;
    }
                                                
  std::string content_gmail = "";

  // ToDo: check for a better way to get the content of the whole file
  std::string line = "";
  while (!file_input.eof())
    {
      std::getline(file_input, line);
      content_gmail = content_gmail + line + "\n";
    }

  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(content_gmail);

  tree<HTML::Node>::iterator beg = dom.begin();
  tree<HTML::Node>::iterator end = dom.end();

  std::string ct = "";
  std::string link_title_str = "";
  std::string deadline_str = "";

  tree<HTML::Node>::iterator previous_bold_it = NULL;
  
  for (tree<HTML::Node>::iterator it = beg; it != end; ++it)
    {
      if (it->tagName() == "strong")
        {
          ct = it->content(content_gmail);
          if (ct.find("Provided by:") != std::string::npos)
            {
              link_title_str = previous_bold_it->content(content_gmail);
            }
          if (ct.find("Application Deadline") != std::string::npos)
            {
              tree<HTML::Node>::iterator jt = it;

              // To deal with the following form:
              // <strong><span style="background: white">Application Deadline</span></strong>
              // <span style="background: white">&nbsp;22 September 2014</span><br />
              ++jt;
              ++jt;
              ++jt;
              deadline_str = jt->content(content_gmail);

              //
              // To deal with the following form:
              // <strong>Application Deadline</strong> 31 October 2014<br />
              //
              if (deadline_str == "")
                {
                  for (jt = it; jt != end; ++jt)
                    {
                      if (jt->tagName() == "br")
                        {
                          jt--;
                          deadline_str = jt->text();
                          break;
                        }
                    }
                }

              fetchOneScholarshipPosition(file_output, now, count,
                                          link_title_str, deadline_str);
            }
          
          previous_bold_it = it;
        }
    }

  DBGINFO("Fetched " << count << " scholarship items from ScholarshipPositions-Gmail!")
}



void
Fetcher::fetchOneScholarshipPosition(std::ofstream &file_output,
                                     const std::string &now,
                                     std::size_t &count,
                                     const std::string &link_title_str,
                                     const std::string &deadline_str)
{
  std::string sign1 = "<a href=\"";
  std::string sign2 = "/\"";
  std::string sign3 = "\">";
  std::string sign4 = "</a>";

  std::string s = link_title_str;
  strReplace(s, "\n", " ");

  FetchedInfoScholarship fis;
  fis.m_URL = getStringInBetween(s, sign1, sign2);
  fis.m_Title = getStringInBetween(s, sign3, sign4);

  DatePtr deadline = DateConverter::instance()->convert(deadline_str);

  if (deadline.get())
    {
      fis.m_Deadline = boost::gregorian::to_iso_string(*deadline);

      writeInputToManager(file_output, fis, now, count);
      count++;
    }
}
