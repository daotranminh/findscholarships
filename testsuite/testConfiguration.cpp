#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "testConfiguration"
#include <boost/test/unit_test.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

BOOST_AUTO_TEST_CASE ( testConfiguration )
{
  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU)

  std::string config_filename = "/Users/minhdt/Documents/softwares/findscholarships-website/config.cfg";
  std::string path_root = "/Users/minhdt/Documents/softwares/findscholarships-website/";
  Configuration *config = Configuration::instance();

  config->readConfig(config_filename);

  BOOST_CHECK_EQUAL(config->pathRoot(), path_root);
}
