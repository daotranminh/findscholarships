#ifndef ___FETCHER_HPP___
#define ___FETCHER_HPP___

#include <curl/curl.h>
#include "FetchedInfo.hpp"

class Fetcher
{
public:
  ~Fetcher();

  std::string
  fetchSingle(const std::string &url);

  void
  fetchMultiple(const std::string &filename,
		FetchedInfoVecPtr fetched_infos);

  void
  fetchDbworld(FetchedInfoVecPtr fetched_infos);

private:
  CURL *m_Curl;
  CURLcode m_Res;
};


size_t 
writeData(char *ptr, 
	  std::size_t size, 
	  std::size_t nmemb, 
	  void *userdata);


#endif // ___FETCHER_HPP___
