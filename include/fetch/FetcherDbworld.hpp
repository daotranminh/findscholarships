#ifndef ___FETCHER_DBWORLD_HPP__
#define ___FETCHER_DBWORLD_HPP__

#include "fetch/FetcherBase.hpp"

class FetcherDbworld : public FetcherBase
{
public:
  FetcherDbworld(const std::string &path,
		 const std::string &pathDatabase,
		 const std::string &filename_marker_dbworld,
		 const std::string &filename_input_dbworld);

  ~FetcherDbworld();

  void fetch();

private:
  const std::string m_FilenameMarkerDbworld;
  const std::string m_FilenameInputDbworld;
};

#endif // ___FETCHER_DBWORLD_HPP__
