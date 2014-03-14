#include <assert.h>
#include <iostream>
#include <fstream>

#include "utilities/Configuration.hpp"
#include "utilities/HelperFunctions.hpp"
#include "utilities/Logger.hpp"
#include "htmlgen/DataBase.hpp"

typedef Storage::const_iterator StorageConstIterator;
typedef std::pair<StorageConstIterator, StorageConstIterator> StorageConstIteratorPair;

// Database text format:
//
// 3*n lines for n scholarships
//
// Scholarship[i]:
//
// Line 3*i-2: deadline of the form yyyymmdd
// Line 3*i-1: title in string
// Line 3*i:   original link from which the scholarship was crawled

Database::Database()
{
  for (std::size_t i = 0; i < TOTAL_STORAGES; ++i)
    {
      storages.push_back(new Storage);
    }
  
  // Initialize lower_bound to today+1month
  // as we only show scholarships having deadline in more than a month from the posting date.
  // Otherwise, it will be useless for the reader.
  
  boost::gregorian::date today = boost::gregorian::day_clock::local_day();
  boost::gregorian::months one_month(1);
  boost::gregorian::date m_LowerBound = today + one_month;  
}



Database::~Database()
{
  // clean up all storages
  for (std::size_t i = 0; i < TOTAL_STORAGES; ++i)
    {
      Storage* s = storages[i];
      
      for (Storage::iterator it = s->begin(); it != s->end(); ++it)
	delete it->first; // deadline, of type Date_t*
      
      delete s;
      s = 0;
    }
}
