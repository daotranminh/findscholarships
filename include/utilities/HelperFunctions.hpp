#ifndef ___HELPER_FUNCTIONS_HPP___
#define ___HELPER_FUNCTIONS_HPP___

#include <string>

void
killSpecialChar(std::string& s, 
		char c);

void
strReplace(std::string& s, 
	   const std::string& source, 
	   const std::string& target);

void
strTrim(std::string& s);


const std::string 
currentDateTime();

#endif // ___HELPER_FUNCTIONS_HPP___
