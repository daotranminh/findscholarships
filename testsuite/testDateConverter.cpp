#include "utilities/DateConverter.hpp"
#include "utilities/Logger.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "testDateConverter"
#include <boost/test/unit_test.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

BOOST_AUTO_TEST_CASE ( testDateConverter )
{
  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU)

  DateConverter *dc = DateConverter::instance();
  DatePtr d = dc->convert("1s2 November 2014");

  if (d.get() == NULL)
    {
      std::cout << "NULL" << std::endl;
    }
}
