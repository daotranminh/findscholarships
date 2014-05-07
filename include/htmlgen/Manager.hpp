#ifndef ___MANAGER_HPP___
#define ___MANAGER_HPP___

#include "fetch/FetchedInfoScholarship.hpp"
#include "htmlgen/Database.hpp"
#include "htmlgen/HtmlGenBase.hpp"

class Manager
{
public:
  void
  processBatch(const std::string &file_url_collection, 
	       Database &db);
	
private:
  bool
  getInput(std::ifstream &file_input,
	   FetchedInfoScholarship &fis);
  
  void
  processSingle(FetchedInfoScholarship &fis, 
		Database &db);
  
  HtmlGenBase* 
  getGenerator(const std::string &url);
};


#endif // ___MANAGER_HPP___
