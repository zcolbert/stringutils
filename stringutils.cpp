#include "stringutils.h"
#include <sstream>
#include <stdexcept>
#include <iostream>


std::string join(const std::vector<std::string>& parts)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts[0]; }

    size_t size = 0;
    for (const auto& s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);
    for (const auto& s: parts) { result.append(s); }
    return result;
}
std::string join(const std::vector<std::string>& parts, char delim)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts[0]; }

    size_t size = parts.size() - 1;
    for (const auto& s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);

    for (size_t i=0; i<parts.size()-1; ++i) {
        result.append(parts[i]);
        result += delim;
    }
    result.append(parts[parts.size()-1]);
    return result;
}
std::string join(const std::vector<std::string>& parts, const std::string& delim)
{
    if (parts.empty()) { return ""; }
    if (parts.size() == 1) { return parts[0]; }

    size_t size = delim.size() * (parts.size()-1);
    for (const auto& s: parts) { size += s.size(); }
    std::string result;
    result.reserve(size);

    for (size_t i=0; i<parts.size()-1; ++i) {
        result.append(parts[i]);
        result += delim;
    }
    result.append(parts[parts.size()-1]);
    return result;
}

std::string replace(const std::string& orig, char from, char to)
{ throw std::runtime_error("Not implemented"); }

std::string replace(const std::string& orig, const std::string& from, const std::string& to)
{ throw std::runtime_error("Not implemented"); }

std::vector<std::string> split(const std::string& orig)
{
    std::vector<std::string> parts;
    std::string buf;
    buf.reserve(orig.length());

    for (auto c: orig) {
        if (isspace(c)) {
            if (!buf.empty()) {
                parts.push_back(buf);
                buf.clear();
            }
        }
        else {
            buf += c;
        }
    }
    if (!buf.empty()) { parts.push_back(buf); }
    return parts;
}
std::vector<std::string> split(const std::string& orig, char delim)
{
    std::vector<std::string> parts;
    std::string buf;
    buf.reserve(orig.length());

    for (auto c: orig) {
        if (c == delim) {
            if (!buf.empty()) {
                parts.push_back(buf);
                buf.clear();
            }
        }
        else {
            buf.push_back(c);
        }
    }
    if (!buf.empty()) { parts.push_back(buf); }
    return parts;
}
std::vector<std::string> split(const std::string& orig, const std::string& delim)
{
    std::vector<std::string> parts;
    if (orig.empty()) { return parts; }

    size_t pos = 0;
    size_t end = orig.length() - delim.length() + 1;
    std::string buf;
    while (pos <= end) {
        if (orig.substr(pos, delim.length()) == delim) {
            if (!buf.empty()) {
                parts.push_back(buf);
                buf.clear();
            }
            pos += delim.length();
        }
        else {
            buf.push_back(orig[pos]);
            ++pos;
        }
    }
    if (!buf.empty()) { parts.push_back(buf); }
    return parts;
}

std::string lstrip(const std::string& orig)
{
    size_t pos = orig.find_first_not_of(" \t\n");
    if (pos == 0) {
        return orig;
    } else if (pos == std::string::npos) {
        return "";
    } else {
        return orig.substr(pos, orig.length()-pos);
    }
}
std::string lstrip(const std::string& orig, char delim)
{
    size_t pos = orig.find_first_not_of(delim);
    if (pos == 0) {
        return orig;
    } else if (pos == std::string::npos) {
        return "";
    } else {
        return orig.substr(pos, orig.length()-pos);
    }
}
std::string lstrip(const std::string& orig, const std::string& delim)
{
    if (delim.empty()) { return orig; }
    size_t start = 0;
    while(orig.substr(start, delim.length()) == delim && start < orig.length()) {
        start += delim.length();
    }
    return start == 0 ? orig : orig.substr(start, orig.length());
}

std::string rstrip(const std::string& orig)
{
    size_t pos = orig.find_last_not_of(" \t\n");
    return pos == std::string::npos ? "" : orig.substr(0, pos+1);
}
std::string rstrip(const std::string& orig, char delim)
{
    size_t pos = orig.find_last_not_of(delim);
    return pos == std::string::npos ? "" : orig.substr(0, pos+1);
}
std::string rstrip(const std::string& orig, const std::string& delim)
{
    if (delim.empty() || (orig.length() < delim.length())) { return orig; }
    size_t pos = orig.length();
    while (pos >= 0 && pos >= delim.length()) {
        pos -= delim.length();
        if (orig.substr(pos, delim.length()) != delim) {
            pos += delim.length();
            break;
        }
    }
    return orig.substr(0, pos);
}

std::string strip(const std::string& orig) {
    return rstrip(lstrip(orig));
}
std::string strip(const std::string& orig, char delim) {
    return rstrip(lstrip(orig, delim), delim);
}
std::string strip(const std::string& orig, const std::string& delim) {
    return rstrip(lstrip(orig, delim), delim);
}
