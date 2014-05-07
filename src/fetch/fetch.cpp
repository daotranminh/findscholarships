#include <string>

#include <boost/program_options.hpp>

#include "fetch/Fetcher.hpp"
#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"
#include "utilities/ProgramOptions.hpp"


int main(int argc, char *argv[])
{
  std::string fetch_from = "all";

  const char *help_description = "\nUsage: fetch [--from=all/manual/dbworld]\n";
  boost::program_options::options_description desc(help_description);

  desc.add_options()
    (HELP, "produce help and usage message")
    (FROM, boost::program_options::value<std::string>(&fetch_from)->default_value("all"), "choose fetching source")
    ;

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count(HELP))
    {
      std::cerr << desc << std::endl;
      exit(1);
    }


  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU);

  std::string config_filename = "/Users/minhdt/Documents/Study/findscholarships-website/config.cfg";

  Configuration* config = Configuration::instance();
  config->readConfig(config_filename);

  DBGINFO("Fetching starts...");

  Fetcher fc(config->pathTemp(),
	     config->pathDatabase(),
	     config->inputLinks(), 
	     config->inputFetched(),
	     config->markerDbworld(),
	     config->inputDbworld());

  if (fetch_from == "manual")
    {
      DBGDEBUG("pathTemp      = " << config->pathTemp())
      DBGDEBUG("inputLinks    = " << config->inputLinks())
      DBGDEBUG("inputFetched  = " << config->inputFetched())

      fc.fetchMultiple();
    }
  else if (fetch_from == "dbworld")
    {
      DBGDEBUG("inputDatabase = " << config->pathDatabase())
      DBGDEBUG("markerDbworld = " << config->markerDbworld())
      DBGDEBUG("inputDbworld  = " << config->inputDbworld())
      fc.fetchDbworld();
    }
  else
    {
      assert (fetch_from == "all");
      DBGDEBUG("pathTemp      = " << config->pathTemp())
      DBGDEBUG("inputDatabase = " << config->pathDatabase())
      DBGDEBUG("inputLinks    = " << config->inputLinks())
      DBGDEBUG("inputFetched  = " << config->inputFetched())
      DBGDEBUG("markerDbworld = " << config->markerDbworld())

      fc.fetchMultiple();
      fc.fetchDbworld();
    }

  DBGINFO("Fetching finished...");
}
