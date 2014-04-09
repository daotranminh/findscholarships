#ifndef ___HTML_GEN_SCHOLARSHIPS_LINKS_HPP___
#define ___HTML_GEN_SCHOLARSHIPS_LINKS_HPP___

#include "htmlgen/HtmlGenBase.hpp"

class HtmlGenScholarshipsLinks : public HtmlGenBase
{
public:
  void
  generate(DatePtr &deadline,
	   std::string &title,
	   const std::string &filecontent);

private:
  void
  cleanUp(std::string &s);
};


#endif // ___HTML_GEN_SCHOLARSHIPS_LINKS_HPP___
