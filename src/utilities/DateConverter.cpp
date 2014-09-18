#include "utilities/DateConverter.hpp"


DateConverter::DateConverter()
{ 
}



DateConverter*
DateConverter::instance()
{
  if (_instance == NULL)
    {
      _instance = new DateConverter;
    }

  return _instance;
}



DatePtr
DateConverter::convert(const std::string &s)
{
}
