#ifndef ___FETCHER_HPP___
#define ___FETCHER_HPP___

#include <curl/curl.h>
#include "fetch/FetchedInfo.hpp"
#include "fetch/FetchedInfoScholarship.hpp"
#include "html/ParserDom.h"

using namespace htmlcxx;

class Fetcher
{
public:
  Fetcher(const std::string &path,
	  const std::string &pathDatabase,
	  const std::string &filename_input,
	  const std::string &filename_output,
	  const std::string &filename_marker_dbworld,
	  const std::string &filename_input_dbworld,
          const std::string &filename_html_scholarship_positions_gmail,
          const std::string &filename_input_scholarship_positions_gmail);

  ~Fetcher();

  std::string
  fetchSingle(const std::string &url);
    
  void
  fetchMultiple();

  void
  fetchDbworld();

  void
  fetchScholarshipPositionsGmail();

private:
  bool
  getInput(std::ifstream &file_input,
	   FetchedInfoScholarship &fis);

  FetchedInfoScholarship
  lastCrawledDbworldJob();

  void
  cacheCrawledDbworldJob(const FetchedInfoScholarship &fis);

  void
  writeInputToManager(std::ofstream &file_input_to_manager,
		      FetchedInfoScholarship &fis,
		      const std::string &now,
		      const std::size_t count);
  
  int
  fetchDbworldRow(const std::string &dbworld,
		  tree<HTML::Node>::iterator row_it,
		  FetchedInfoScholarship &fis);

  const std::string 
  currentDateTime();

  bool
  isPotentialTitle(const std::string &s);

  void
  fetchOneScholarshipPosition(const std::string &title,
                              std::string &deadline);

private:
  CURL *m_Curl;
  CURLcode m_Res;

  const std::string m_Path;
  const std::string m_FilenameInput;
  const std::string m_FilenameOutput;
  const std::string m_FilenameMarkerDbworld;
  const std::string m_FilenameInputDbworld;
  const std::string m_FilenameHtmlScholarshipPositionsGmail;
  const std::string m_FilenameInputScholarshipPositionsGmail;
};


size_t 
writeData(char *ptr, 
	  std::size_t size, 
	  std::size_t nmemb, 
	  void *userdata);


#endif // ___FETCHER_HPP___
