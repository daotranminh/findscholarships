#include <string>

#include "fetch/Fetcher.hpp"
#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"


int main()
{
  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU);

  std::string config_filename = "/Users/minhdt/Documents/Study/findscholarships-website/config.cfg";

  Configuration* config = Configuration::instance();
  config->readConfig(config_filename);

  DBGINFO("Fetching starts...");

  Fetcher fc(config->pathTemp(), config->inputLinks(), config->inputFetched());
  fc.fetchMultiple();

  DBGINFO("Fetching finished...");
}
