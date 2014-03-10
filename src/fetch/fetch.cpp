#include <string>

#include "fetch/Fetcher.hpp"
#include "utilities/Logger.hpp"


int main()
{
  DBGINIT(std::cerr, Logger::INFO | Logger::ERRO | Logger::VERB | Logger::DEBU);

  std::string path = "./";
  std::string input = "input.txt";
  std::string output = "fetched_input.txt";

  DBGINFO("Fetching starts...");

  Fetcher fc(path, input, output);
  fc.fetchMultiple();

  DBGINFO("Fetching finished...");
}
