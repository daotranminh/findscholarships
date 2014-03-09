#include "fetch/FetchedInfo.hpp"

FetchedInfo::FetchedInfo()
  : m_Deadline(""),
    m_Title(""),
    m_URL(""),
    m_HTMLCode("")
{ }



FetchedInfo::FetchedInfo(const std::string &deadline,
			 const std::string &url)
  : m_Deadline(deadline),
    m_Title(""),
    m_URL(url),
    m_HTMLCode("")
{ }



FetchedInfo::FetchedInfo(const std::string &deadline,
			 const std::string &title,
			 const std::string &url)
  : m_Deadline(deadline),
    m_Title(title),
    m_URL(url),
    m_HTMLCode("")
{ }
