#include "htmlgen/Database.hpp"
#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"
#include <fstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "testDatabase"
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/bind.hpp>


void
createDummyDatabase(const std::size_t db_index)
{
  // create 1 expired data entry and 1 still valid
  Date_t today = boost::gregorian::day_clock::local_day();
  boost::gregorian::months one_month(1);
  boost::gregorian::months two_months(2);
  
  Date_t past_1_month = today - one_month;
  Date_t in_2_months = today + two_months;

  Configuration *config = Configuration::instance();
  const StringVec &path_storages = config->pathStorages();
  const StringVec &categories = config->categories();
  const std::string filename = path_storages[db_index];
  const std::string category = categories[db_index];

  std::ofstream db_file(filename.c_str());
  db_file << boost::gregorian::to_iso_string(past_1_month) << std::endl
	  << category << " expired" << std::endl
	  << "http://www." << category << ".expired.html" << std::endl
	  << boost::gregorian::to_iso_string(in_2_months) << std::endl
	  << category << " valid" << std::endl
	  << "http://www." << category << ".valid.html" << std::endl;
  
  db_file.close();
}



void
insertDummy(Database &db,
	    std::size_t db_index)
{
  // create 1 expired data entry and 1 still valid
  Date_t today = boost::gregorian::day_clock::local_day();
  boost::gregorian::months one_month(1);
  boost::gregorian::months two_months(2);
  
  Date_t past_2_months = today - two_months;
  Date_t in_1_month = today + one_month;

  DatePtr past_2_months_ptr = std::make_shared<Date_t>(past_2_months);
  DatePtr in_1_month_ptr = std::make_shared<Date_t>(in_1_month);

  Configuration *config = Configuration::instance();
  const StringVec &categories = config->categories();
  const std::string category = categories[db_index];

  Title title_expired(category + " expired 222"); 
  std::string link_expired = "http://www." + category + ".expired222.html";

  Title title_valid(category + " valid 222");
  std::string link_valid = "http://www." + category + ".valid222.html";

  db.insert(db_index, past_2_months_ptr, title_expired, link_expired);
  db.insert(db_index, in_1_month_ptr, title_valid, link_valid);
}



void
check_file_length(std::size_t db_index)
{
  Configuration *config = Configuration::instance();
  const StringVec &path_storages = config->pathStorages();
  const StringVec &categories = config->categories();
  const std::string filename = path_storages[db_index];
  const std::string category = categories[db_index];

  std::size_t number_entries;
  if (db_index < TOTAL_STORAGES - 1)
    number_entries = 2;
  else
    number_entries = 12;
}


BOOST_AUTO_TEST_CASE ( testDatabase )
{
  DBGINIT(std::cerr, Logger::INFO | Logger::VERB | Logger::DEBU)

  std::string config_filename = "/Users/minhdt/Documents/Study/github/findscholarships/examples/testDatabase/config.cfg";
  Configuration *config = Configuration::instance();
  config->readConfig(config_filename);

  // create some dummy database for loading
  for (std::size_t i = 0; i < TOTAL_STORAGES-1; ++i)
    {
      createDummyDatabase(i);
    }

  // test loading database ******************************************************
  Database db;
  db.loadDatabase();

  const StorageVec &storages = db.getStorages();
  StorageVec::const_iterator homepage_it = storages.end();
  homepage_it--;

  // each category should have only 1 entry (corresponding to the valid one)
  for (StorageVec::const_iterator it = storages.begin(); it != homepage_it; ++it)
    {
      const StoragePtr s = *it;
      BOOST_CHECK_EQUAL(s->size(), 1);
    }

  // the homepage database of course has more entries
  const StoragePtr homepage_storage = *homepage_it;
  BOOST_CHECK_EQUAL(homepage_storage->size(), storages.size()-1);

  // test inserting data entries ************************************************
  for (std::size_t i = 0; i < TOTAL_STORAGES-1; ++i)
    {
      insertDummy(db, i);
    }

  // now each category should have 2 entries (corresponding to the valid ones)
  for (StorageVec::const_iterator it = storages.begin(); it != homepage_it; ++it)
    {
      const StoragePtr s = *it;
      BOOST_CHECK_EQUAL(s->size(), 2);
    }
  BOOST_CHECK_EQUAL(homepage_storage->size(), 2*(storages.size()-1));

  // test storing database *****************************************************
  db.storeDatabase();
  for (std::size_t i = 0; i < TOTAL_STORAGES; i++)
    {
      check_file_length(i);
    }
}
