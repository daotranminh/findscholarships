#ifndef ___FETCHED_INFO_HPP___
#define ___FETCHED_INFO_HPP___

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

struct FetchedInfo
{
  std::string m_Deadline;
  std::string m_Title;
  std::string m_URL;
  std::string m_HTMLCode;

  FetchedInfo();

  FetchedInfo(const std::string &deadline,
	      const std::string &url);

  FetchedInfo(const std::string &deadline,
	      const std::string &title,
	      const std::string &url);
};

typedef boost::shared_ptr<FetchedInfo> FetchedInfoPtr;
typedef std::vector<FetchedInfoPtr> FetchedInfoVec;
typedef boost::shared_ptr<FetchedInfoVec> FetchedInfoVecPtr;


#endif //  ___FETCHED_INFO_HPP___
