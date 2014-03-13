#include <string>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "testBoostDateTime"
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/bind.hpp>

BOOST_AUTO_TEST_CASE ( testBoostDateTime )
{
  std::string s1 = "20140926";
  boost::gregorian::date d1(boost::gregorian::from_undelimited_string(s1));
  std::cout << boost::gregorian::to_iso_extended_string(d1) << std::endl;

  std::string s2 = "24-Nov-1981";
  boost::gregorian::date d2(boost::gregorian::from_uk_string(s2));
  std::cout << boost::gregorian::to_iso_extended_string(d2) << std::endl;
}
