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

  void
  checkMonth(std::string &s,
             const std::vector<std::string> &strs,
             std::size_t &count_month,
             std::size_t &month);

  void
  checkYear(std::string &s,
            const std::size_t testYear,
            std::size_t &year);

  static DateConverter *_instance;
};

#endif // __DATE_CONVERTER_HPP__
