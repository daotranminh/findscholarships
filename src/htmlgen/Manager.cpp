#include <fstream>

#include "htmlgen/HtmlGenScholarshipPosition.hpp"
#include "htmlgen/HtmlGenScholarshipsLinks.hpp"
#include "htmlgen/Manager.hpp"
#include "utilities/ConstantStrings.hpp"
#include "utilities/Logger.hpp"


bool
Manager::getInput(std::ifstream &file_input,
		  DatePtr &deadline,
		  std::string &str_title,
		  std::string &filename,
		  std::string &url)
{
  std::string line;
  std::getline(file_input, line);
	
  if (line == "") return false;
  assert (line.compare(ConstantStrings::instance()->PrefixBegin) == 0);
  
  std::getline(file_input, line);
  if (line == "") return false;
  
  while (line.compare(ConstantStrings::instance()->PrefixEnd) != 0)
    {
      bool passed = false;
      if (line.find(ConstantStrings::instance()->PrefixDeadline) != std::string::npos)
	{
	  std::string str_deadline = line.substr(ConstantStrings::instance()->PrefixDeadline.length());
	  Date_t dl(boost::gregorian::from_undelimited_string(str_deadline));
	  deadline = std::make_shared<Date_t>(dl);
	  passed = true;
	}
      
      if (!passed && line.find(ConstantStrings::instance()->PrefixTitle) != std::string::npos)
	{
	  str_title = line.substr(ConstantStrings::instance()->PrefixTitle.length());
	  //DBGDEBUG("Manager::getInput: str_title = " << str_title);
	  passed = true;
	}
      
      if (!passed && line.find(ConstantStrings::instance()->PrefixFilename) != std::string::npos)
	{
	  filename = line.substr(ConstantStrings::instance()->PrefixFilename.length());
	  //DBGDEBUG("Manager::getInput: filename = " << filename);
	  passed = true;
	}
      
      if (!passed && line.find(ConstantStrings::instance()->PrefixURL) != std::string::npos)
	{
	  url = line.substr(ConstantStrings::instance()->PrefixURL.length());
	  //DBGDEBUG("Manager::getInput: url = " << url);
	  passed = true;
	}
      
      std::getline(file_input, line);
    }
  
  return true;
}



void
Manager::processBatch(const std::string &file_url_collection, 
		      Database &db)
{
  // read from file_url_collection and call processSingle for each pair <filename,url>
  std::ifstream file_input(file_url_collection.c_str());
  
  if (file_input.is_open())
    {
      while (file_input.good()) 
	{
	  DatePtr deadline;
	  std::string title = "";
	  std::string filename = "";
	  std::string url = "";
	  
	  if (!getInput(file_input, deadline, title, filename, url)) break;
	  
	  processSingle(deadline, title, filename, url, db);
	}
      
      db.showDatabase();
      db.storeDatabase();
      db.writeToCategoryFile();
      db.writeNotification(true /* singleLine */);
    }
  else 
    {
      DBGERR(__FUNCTION__ << ": Cannot open file \"" << file_url_collection << "\"!")
    }
  
}



void
Manager::processSingle(DatePtr &deadline,
		       std::string &str_title,
		       const std::string &filename, 
		       const std::string &url, 
		       Database &db)
{
  //DBGDEBUG("processSingle: deadline = " << deadline << ", title = " << str_title);
  HtmlGenBase* generator = getGenerator(url);
  assert (generator != NULL);
  
  
  generator->process(deadline, str_title, filename);
  const HtmlResult& result = generator->getHtmlResult();
  
  if (result.getDeadline().get() != NULL)
    {
      // write to files
      const std::string& full_html_code = result.getFullHtmlCode();
      std::string full_path = result.getTitle().getFileLocation(result.getDeadline());
      
      std::ofstream html_file(full_path.c_str());
      if (html_file.is_open())
	{
	  html_file << full_html_code;
	  html_file.close();
	  
	  // insert to database
	  const Title& title = result.getTitle();
	  const StorageVec st = db.getStorages();
	  std::size_t index = title.classifiedIndex();
	  StoragePtr s = st[index];
	  
	  db.insert(s, result.getDeadline(), title, url, true /* is_new */);
	  //db.showDatabase();
	}
      else
	{
	  DBGERR(__FUNCTION__ << ": Cannot write to file \"" << full_path << "\"!")
        }
    }
	
  // clean up
  delete generator;
  generator = NULL;
}



HtmlGenBase*
Manager::getGenerator(const std::string &url)
{
  std::size_t pos = url.find("www.scholarships-links.com");
  if (pos != std::string::npos)
    {
      return (new HtmlGenScholarshipsLinks);
    }
  
  // pos = url.find("scholarshipsbank.com");
  // if (pos != std::string::npos)
  //   {
  //     return (new HtmlGenScholarshipsBank);
  //   }
  
  pos = url.find("scholarship-positions.com");
  if (pos != std::string::npos)
    {
      return (new HtmlGenScholarshipPosition);
    }
  
  // pos = url.find("www.cs.wisc.edu");
  // if (pos != std::string::npos)
  //   {
  //     return (new HtmlGenDbWorld);
  //   }
  
  return NULL;
}
