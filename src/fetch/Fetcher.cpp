#include "fetch/Fetcher.hpp"
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>



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



void
Fetcher::fetchMultiple(const std::string &filename,
		       FetchedInfoVecPtr fetched_infos)
{
  std::ifstream file_input(filename.c_str());

  if (!file_input.is_open())
    {
      std::cerr << "Cannot open file \"" << filename << "\" for reading!" << std::endl;
      return;
    }

  while (file_input.good())
    {
      std::string deadline = "";
      std::string url = "";

      std::getline(file_input, deadline);
      if (deadline == "") return;

      // only accept deadlines of the form YYYYMMDD
      if (deadline.length() == 8)
	{
	  std::getline(file_input, url);
	}
      else
	{
	  url = deadline;
	  deadline = "";
	}

      assert (url.find("http://") != std::string::npos);

      FetchedInfoPtr fetched_info(new FetchedInfo(deadline, url));
      fetched_info->m_HTMLCode = fetchSingle(url);
      fetched_infos->push_back(fetched_info);
    }

  file_input.close();
}



void
Fetcher::fetchDbworld(FetchedInfoVecPtr fetched_infos)
{
}
