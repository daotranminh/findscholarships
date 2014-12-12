#include "fetch/FetcherDbworld.hpp"

FetcherDbworld::FetcherDbworld(const std::string &path,
			       const std::string &pathDatabase,
			       const std::string &filename_marker_dbworld,
			       const std::string &filename_input_dbworld)
  : FetcherBase(path, pathDatabase),
    m_FilenameMarkerDbworld(m_Path + filename_marker_dbworld),
    m_FilenameInputDbworld(m_Path + filename_input_dbworld)
{ }



FetcherDbworld::~FetcherDbworld()
{ }



void 
FetcherDbworld::fetch()
{ 
}
