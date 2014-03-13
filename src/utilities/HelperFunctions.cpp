#include "utilities/HelperFunctions.hpp"



void
killSpecialChar(std::string& s, 
		char c)
{
  std::size_t pos = s.find(c);
  while (pos != std::string::npos)
    {
      s.replace(pos, 1, "");
      pos = s.find(c);
    }
}



void
strReplace(std::string& s, 
	   const std::string& source, 
	   const std::string& target)
{
  std::size_t pos = s.find(source);
  if (pos != std::string::npos)
    {
      s.replace(pos, source.length(), target);
    }
}



// trim spaces 
void
strTrim(std::string& s)
{
  size_t position = s.find_last_not_of(" \t");
  
  if (std::string::npos != position)
    {
      s = s.substr(0, position+1);
    }
  
  position = s.find_first_not_of(" \t");
  if (std::string::npos != position)
    {
      s = s.substr(position);
    }
}
