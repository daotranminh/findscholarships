#ifndef ___DATABASE_HPP___
#define ___DATABASE_HPP___

#include <map>
#include <vector>

#include <boost/date_time/gregorian/gregorian.hpp>
#include "htmlgen/DataEntry.h"

typedef boost::gregorian::date Date_t;
struct DateCompare
{
  bool
  operator()(const Date_t* date1, const Date_2* date2) // date1 > date2
  {
    return (date1 > date2);
  }
}


typedef std::multimap<Date_t*, DataEntry, DateCompare> Storage;
typedef std::vector<Storage*> StorageVec;

class Database
{
public:
  Database();
	
  ~Database();
  
  void 
  loadDatabase();
  
  void
  storeDatabase();
  
  const StorageVec&
  getStorages() const;
  
  void
  insert(Storage* to_load, 
	 Date_t* deadline, 
	 const Title& title, 
	 const std::string& orig_link,
	 bool is_new = false);
  
  void
  writeToCategoryFile();
  
  void
  writeNotification(bool singleLine);
  
  void
  showDatabase();
	
private:
  void
  loadDatabase(const std::string& filename, Storage* to_load);
  
  bool
  insertWithCheck(Storage* to_load,
		  Date_t* deadline,
		  const Title& title,
		  const std::string& orig_link,
		  bool is_new = false);
  
  void
  storeDatabase(const std::string& filename, 
		Storage* to_store);
	
  void
  writeToCategoryFile(const std::string& filename, 
		      const std::string& title,
		      Storage* to_write);
  
  void
  showStorage(Storage* to_show);
  
private:
  StorageVec m_Storages;	
  Date_t* m_LowerBound;
};


#endif // ___DATABASE_HPP___
