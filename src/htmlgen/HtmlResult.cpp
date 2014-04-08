#include "htmlgen/HtmlResult.hpp"

HtmlResult::HtmlResult()
: m_FullHtmlCode("")
{ }



HtmlResult::HtmlResult(const std::string& full_html_code,
		       const DatePtr &deadline,
		       const Title &title) 
: m_FullHtmlCode(full_html_code),
  m_Deadline(deadline),
  m_Title(title)
{ }



const std::string&
HtmlResult::getFullHtmlCode() const
{
  return m_FullHtmlCode;
}



void
HtmlResult::setFullHtmlCode(const std::string& fhc)
{
  m_FullHtmlCode = fhc;
}



DatePtr
HtmlResult::getDeadline() const
{
  return m_Deadline;
}


void
HtmlResult::setDeadline(const DatePtr &dl)
{
  m_Deadline = dl;
}



const Title&
HtmlResult::getTitle() const
{
  return m_Title;
}


void
HtmlResult::setTitle(const Title& t)
{
  m_Title = t;
}