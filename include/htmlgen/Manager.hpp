#ifndef ___MANAGER_HPP___
#define ___MANAGER_HPP___

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
	   DatePtr &deadline,
	   std::string &str_title,
	   std::string &filename,
	   std::string &url);
  
  void
  processSingle(DatePtr &deadline,
		std::string &str_title,
		const std::string &filename, 
		const std::string &url, 
		Database &db);
  
  HtmlGenBase* 
  getGenerator(const std::string &url);
};


#endif // ___MANAGER_HPP___
