#ifndef ___HTML_GEN_SCHOLARSHIP_POSITION_HPP___
#define ___HTML_GEN_SCHOLARSHIP_POSITION_HPP___

#include "htmlgen/HtmlGenBase.hpp"

class HtmlGenScholarshipPosition : public HtmlGenBase
{
public:
  void
  generate(FetchedInfoScholarship &fis,
	   const std::string &filecontent);
};

#endif // ___HTML_GEN_SCHOLARSHIP_POSITION_HPP___
