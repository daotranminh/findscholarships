#ifndef ___FETCHER_HPP___
#define ___FETCHER_HPP___

#include <curl/curl.h>
#include "fetch/FetchedInfo.hpp"
#include "fetch/FetchedInfoScholarship.hpp"

class Fetcher
{
public:
  Fetcher(const std::string &path,
	  const std::string &pathDatabase,
	  const std::string &filename_input,
	  const std::string &filename_output,
	  const std::string &filename_marker_dbworld,
	  const std::string &filename_input_dbworld);

  ~Fetcher();

  std::string
  fetchSingle(const std::string &url);
    
  void
  fetchMultiple();

  void
  fetchDbworld();

private:
  bool
  getDeadlineTitleURL(std::ifstream &file_input,
		      std::string &deadline,
		      std::string &title,
		      std::string &url);


  FetchedInfoScholarship
  lastCrawledDbworldJob();

  void
  cacheCrawledDbworldJob(const FetchedInfoScholarship &fis);

  void
  writeInputDbworld(std::ofstream &file_input_dbworld,
		    const FetchedInfoScholarship &fis);

  const std::string 
  currentDateTime();

private:
  CURL *m_Curl;
  CURLcode m_Res;

  const std::string m_Path;
  const std::string m_FilenameInput;
  const std::string m_FilenameOutput;
  const std::string m_FilenameMarkerDbworld;
  const std::string m_FilenameInputDbworld;
};


size_t 
writeData(char *ptr, 
	  std::size_t size, 
	  std::size_t nmemb, 
	  void *userdata);


#endif // ___FETCHER_HPP___
