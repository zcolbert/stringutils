#include "stringutils.h"
#include <stdexcept>


std::string join(const std::vector<std::string>& parts)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts.at(0); }

    size_t size = 0;
    for (auto s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);
    for (auto s: parts) { result.append(s); }
    return result;
}
std::string join(const std::vector<std::string>& parts, char delim)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts.at(0); }

    size_t size = parts.size() - 1;
    for (auto s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);

    for (size_t i=0; i<parts.size()-1; ++i) {
        result.append(parts.at(i));
        result += delim;
    }
    result.append(parts.at(parts.size()-1));
    return result;
}
std::string join(const std::vector<std::string>& parts, const std::string& delim)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts.at(0); }

    size_t size = delim.size() * (parts.size()-1);
    for (auto s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);

    for (size_t i=0; i<parts.size()-1; ++i) {
        result.append(parts.at(i));
        result += delim;
    }
    result.append(parts.at(parts.size()-1));
    return result;
}

std::string replace(const std::string& orig, char from, char to)
{ throw std::runtime_error("Not implemented"); }
std::string replace(const std::string& orig, const std::string& from, const std::string& to)
{ throw std::runtime_error("Not implemented"); }

std::vector<std::string> split(const std::string& orig, char delim)
{ throw std::runtime_error("Not implemented"); }
std::vector<std::string> split(const std::string& orig, const std::string& delim)
{ throw std::runtime_error("Not implemented"); }

std::string l_strip(const std::string& orig, char delim)
{ throw std::runtime_error("Not implemented"); }
std::string l_strip(const std::string& orig, const std::string& delim)
{ throw std::runtime_error("Not implemented"); }
std::string l_strip_whitespace(const std::string& orig)
{ throw std::runtime_error("Not implemented"); }

std::string r_strip(const std::string& orig, char delim)
{ throw std::runtime_error("Not implemented"); }
std::string r_strip(const std::string& orig, const std::string& delim)
{ throw std::runtime_error("Not implemented"); }
std::string r_strip_whitespace(const std::string& orig)
{ throw std::runtime_error("Not implemented"); }

std::string strip(const std::string& orig, char delim)
{ throw std::runtime_error("Not implemented"); }
std::string strip(const std::string& orig, const std::string& delim)
{ throw std::runtime_error("Not implemented"); }
std::string strip_whitespace(const std::string& orig)
{ throw std::runtime_error("Not implemented"); }
