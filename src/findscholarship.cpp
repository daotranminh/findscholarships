#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "utilities/Configuration.hpp"
#include "utilities/HelperFunctions.hpp"
#include "utilities/Logger.hpp"
#include "htmlgen/Database.hpp"
#include "htmlgen/HtmlGenBase.hpp"
#include "htmlgen/Manager.hpp"
#include "htmlgen/Title.hpp"


int 
main (int argc, const char *argv[])
{
  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU)
	
  std::string config_filename = "/Users/minhdt/Documents/Study/findscholarships-website/config.cfg";
  
  DBGINFO("Read config")
    
  Configuration* config = Configuration::instance();
  config->readConfig(config_filename);
  
  DBGINFO("Load db")
    
  Database db;
  db.loadDatabase();
  
  DBGINFO("Process batch")
  Manager man;	
  man.processBatch(config->pathTemp() + config->inputFetched(), db);
  
  DBGINFO("Finish!")
    
  return 0;
}
