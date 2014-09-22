#include "fetch/FetcherManual.hpp"

#include "utilities/ConstantStrings.hpp"
#include "utilities/DateType.hpp"
#include "utilities/HelperFunctions.hpp"
#include "utilities/Logger.hpp"


FetcherManual::FetcherManual(const std::string &path,
                             const std::string &pathDatabase,
                             const std::string &filename_input,
                             const std::string &filename_output)
  : FetcherBase(path, pathDatabase),
    m_FilenameInput(m_Path + filename_input),
    m_FilenameOutput(m_Path + filename_output)
{ }



FetcherManual::~FetcherManual()
{ }



void
FetcherManual::fetch()
{
  DBGDEBUG("Fetching from manual input...")

  std::ifstream file_input(m_FilenameInput.c_str());
  std::ofstream file_output(m_FilenameOutput.c_str());

  if (!file_input.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameInput << "\" for reading!" << std::endl;
      return;
    }

  if (!file_output.is_open())
    {
      std::cerr << "Cannot open file \"" << m_FilenameOutput << "\" for writing!" << std::endl;
      return;
    }

  const std::string now = currentDateTime();
  std::size_t count = 0;

  ConstantStrings *constrings = ConstantStrings::instance();

  while (file_input.good())
    {
      FetchedInfoScholarship fis;
      if (!getInput(file_input, fis)) break;

      writeInputToManager(file_output, fis, now, count);
      count++;
    }

  DBGINFO("Fetched " << count << " scholarship items from manual input!")

  file_input.close();
  file_output.close();
}
