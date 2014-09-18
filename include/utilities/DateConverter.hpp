#ifndef __DATE_CONVERTER_HPP__
#define __DATE_CONVERTER_HPP__

#include "utilities/DateType.hpp"

class DateConverter
{
public:
  static DateConverter*
  instance();

  DatePtr
  convert(const std::string &s);

private:
  DateConverter();

  static DateConverter *_instance;
};

#endif // __DATE_CONVERTER_HPP__
