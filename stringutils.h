#pragma once

#include <string>
#include <vector>


std::string join(const std::vector<std::string>& parts);
std::string join(const std::vector<std::string>& parts, char delim);
std::string join(const std::vector<std::string>& parts, const std::string& delim);

std::string replace(const std::string& orig, char from, char to);
std::string replace(const std::string& orig, const std::string& from, const std::string& to);

std::vector<std::string> split(const std::string& orig);
std::vector<std::string> split(const std::string& orig, char delim);
std::vector<std::string> split(const std::string& orig, const std::string& delim);

std::string lstrip(const std::string& orig, char delim);
std::string lstrip(const std::string& orig, const std::string& delim);
std::string lstrip_whitespace(const std::string& orig);

std::string rstrip(const std::string& orig, char delim);
std::string rstrip(const std::string& orig, const std::string& delim);
std::string rstrip_whitespace(const std::string& orig);

std::string strip(const std::string& orig, char delim);
std::string strip(const std::string& orig, const std::string& delim);
std::string strip_whitespace(const std::string& orig);
