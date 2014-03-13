#ifndef ___TITLE_HPP___
#define ___TITLE_HPP___

#include <string>

class Title
{
public:
  enum TitleClassification
    {
      UnderGrad,
      Master,
      PhD,
      PostDoc,
      AcademicJob,
      Unclassified
    };
	
  Title();
  
  Title(const std::string& t);
  
  Title(const Title& other_title);
  
  bool
  operator==(const Title& other_title) const;
  
  TitleClassification
  classification() const;
  
  std::string
  strCategory() const;
  
  std::size_t
  classifiedIndex() const;
  
  std::string
  getClassfiedSubDir() const;
  
  std::string
  getTitle() const;
  
  std::string
  getHtmlTitle() const;
  
  std::string
  getHeadLineTitle() const;
  
  std::string
  getTitleNoSpace() const;
  
private:
  std::string m_Title;
};

#endif // ___TITLE_HPP___
