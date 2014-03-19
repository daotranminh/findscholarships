#ifndef ___DATABASE_HPP___
#define ___DATABASE_HPP___

#include <vector>
#include <map>

#include <boost/date_time/gregorian/gregorian.hpp>
#include "htmlgen/DataEntry.hpp"

typedef boost::gregorian::date Date_t;
typedef std::shared_ptr<Date_t> DatePtr;

struct DateCompare
{
  bool
  operator()(const DatePtr date1, const DatePtr date2) const // date1 > date2
  {
    return (*date1 > *date2);
  }
};


typedef std::multimap<DatePtr, DataEntry, DateCompare> Storage;
typedef std::shared_ptr<Storage> StoragePtr;
typedef std::vector<StoragePtr> StorageVec;



class Database
{
public:
  Database();
	
  void 
  loadDatabase();
  
  void
  storeDatabase();
  
  const StorageVec&
  getStorages() const;
  
  void
  insert(StoragePtr to_load, 
	 DatePtr deadline, 
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
  loadDatabase(const std::string& filename, StoragePtr to_load);
  
  void
  insertWithCheck(StoragePtr to_load,
		  DatePtr deadline,
		  const Title& title,
		  const std::string& orig_link,
		  bool is_new = false);
  
  void
  storeDatabase(const std::string& filename, 
		StoragePtr to_store);
	
  void
  writeToCategoryFile(const std::string& filename, 
		      const std::string& title,
		      StoragePtr to_write);
  
  void
  showStorage(StoragePtr to_show);
  
private:
  StorageVec m_Storages;	
  DatePtr    m_LowerBound;
};


#endif // ___DATABASE_HPP___
