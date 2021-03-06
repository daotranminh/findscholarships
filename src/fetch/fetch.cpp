#include <string>

#include <boost/program_options.hpp>

#include "fetch/FetcherDbworld.hpp"
#include "fetch/FetcherManual.hpp"
#include "fetch/FetcherScholarshipLinks.hpp"
#include "fetch/FetcherScholarshipPositions.hpp"
#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"
#include "utilities/ProgramOptions.hpp"



void
fetchManual()
{
  FetcherManual fm(Configuration::instance()->pathTemp(),
                   Configuration::instance()->pathDatabase(),
                   Configuration::instance()->inputLinks(), 
                   Configuration::instance()->inputFetched());
  
  fm.fetch();
}



void
fetchDbworld()
{
  FetcherDbworld fd(Configuration::instance()->pathTemp(),
                    Configuration::instance()->pathDatabase(),
                    Configuration::instance()->markerDbworld(),
                    Configuration::instance()->inputDbworld());
  
  fd.fetch();
}



void
fetchScholarshipLinks()
{
  FetcherScholarshipLinks fsl(Configuration::instance()->pathTemp(),
                              Configuration::instance()->pathDatabase(),
                              Configuration::instance()->htmlScholarshipLinksGmail(),
                              Configuration::instance()->inputScholarshipLinksGmail());

  fsl.fetch();
}



void
fetchScholarshipPositions()
{
  FetcherScholarshipPositions fsp(Configuration::instance()->pathTemp(),
                                  Configuration::instance()->pathDatabase(),
                                  Configuration::instance()->htmlScholarshipPositionsGmail(),
                                  Configuration::instance()->inputScholarshipPositionsGmail());

  fsp.fetch();
}


int main(int argc, char *argv[])
{
  std::string fetch_from = "all";

  const char *help_description = "\nUsage: fetch [--from=all/manual/dbworld/spgmail/slgmail]\n";
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

  std::string config_filename = "/Users/minhdt/Documents/softwares/findscholarships-website/config.cfg";

  Configuration::instance()->readConfig(config_filename);

  DBGINFO("Fetching starts...");

  if (fetch_from == "manual")
    {
      DBGDEBUG("pathTemp      = " << Configuration::instance()->pathTemp())
      DBGDEBUG("inputLinks    = " << Configuration::instance()->inputLinks())
      DBGDEBUG("inputFetched  = " << Configuration::instance()->inputFetched())

      fetchManual();
    }
  else if (fetch_from == "dbworld")
    {
      DBGDEBUG("inputDatabase = " << Configuration::instance()->pathDatabase())
      DBGDEBUG("markerDbworld = " << Configuration::instance()->markerDbworld())
      DBGDEBUG("inputDbworld  = " << Configuration::instance()->inputDbworld())

      fetchDbworld();
    }
  else if (fetch_from == "spgmail") // Scholarship Positions Gmail.
    {
      DBGDEBUG("inputDatabase = " << Configuration::instance()->pathDatabase())
      DBGDEBUG("pathTemp      = " << Configuration::instance()->pathTemp())
      DBGDEBUG("htmlSPGmail   = " << Configuration::instance()->htmlScholarshipPositionsGmail())
      DBGDEBUG("inputSPGmail  = " << Configuration::instance()->inputScholarshipPositionsGmail())

      fetchScholarshipPositions();
    }
  else if (fetch_from == "slgmail") // Scholarship Links Gmail.
    {
      DBGDEBUG("inputDatabase = " << Configuration::instance()->pathDatabase())
      DBGDEBUG("pathTemp      = " << Configuration::instance()->pathTemp())
      DBGDEBUG("htmlSLGmail   = " << Configuration::instance()->htmlScholarshipLinksGmail())
      DBGDEBUG("inputSLGmail  = " << Configuration::instance()->inputScholarshipLinksGmail())

      fetchScholarshipLinks();
    }
  else
    {
      assert (fetch_from == "all");
      DBGDEBUG("pathTemp      = " << Configuration::instance()->pathTemp())
      DBGDEBUG("inputDatabase = " << Configuration::instance()->pathDatabase())
        //DBGDEBUG("inputLinks    = " << Configuration::instance()->inputLinks())
        //DBGDEBUG("inputFetched  = " << Configuration::instance()->inputFetched())
      DBGDEBUG("markerDbworld = " << Configuration::instance()->markerDbworld())
      DBGDEBUG("htmlSLGmail   = " << Configuration::instance()->htmlScholarshipLinksGmail())
      DBGDEBUG("inputSLGmail  = " << Configuration::instance()->inputScholarshipLinksGmail())
      DBGDEBUG("htmlSPGmail   = " << Configuration::instance()->htmlScholarshipPositionsGmail())
      DBGDEBUG("inputSPGmail  = " << Configuration::instance()->inputScholarshipPositionsGmail())

        //fetchManual();
      fetchDbworld();
      fetchScholarshipLinks();
      fetchScholarshipPositions();
    }

  DBGINFO("Fetching finished...");
}
