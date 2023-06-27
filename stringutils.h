#pragma once

#include <string>
#include <vector>


/***************************************************************************
 * Join a vector of strings into a single string.
****************************************************************************/

std::string join(const std::vector<std::string>& parts);    
std::string join(const std::vector<std::string>& parts, char delim);
std::string join(const std::vector<std::string>& parts, const std::string& delim);


/***************************************************************************
* Remove all instances of a character or substring
****************************************************************************/

std::string remove(const std::string& orig, char target);
std::string remove(const std::string& orig, const std::string& sub);


/***************************************************************************
* Replace all instances of a character or substring
****************************************************************************/

std::string replace(std::string orig, char from, char to);
std::string replace(const std::string& orig, const std::string& from, const std::string& to);


/***************************************************************************
* Split a string at each occurrence of the given delimiter 
****************************************************************************/

std::vector<std::string> split(const std::string& orig);
std::vector<std::string> split(const std::string& orig, char delim);
std::vector<std::string> split(const std::string& orig, const std::string& delim);


/***************************************************************************
* Strip a character or substring from the ends of a string
****************************************************************************/

// Strip from the beginning of the string.

std::string lstrip(const std::string& orig);
std::string lstrip(const std::string& orig, char delim);
std::string lstrip(const std::string& orig, const std::string& delim);


// Strip from the end of the string

std::string rstrip(const std::string& orig);
std::string rstrip(const std::string& orig, char delim);
std::string rstrip(const std::string& orig, const std::string& delim);


// Strip from the beginning and end of the string

std::string strip(const std::string& orig);
std::string strip(const std::string& orig, char delim);
std::string strip(const std::string& orig, const std::string& delim);


/***************************************************************************
* Convert the case of the entire string
****************************************************************************/

std::string tolower(const std::string& orig);
std::string toupper(const std::string& orig);

