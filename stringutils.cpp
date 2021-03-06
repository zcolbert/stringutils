#include "stringutils.h"


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

std::string remove(const std::string& orig, char target) {
    std::string buf;
    buf.reserve(orig.length());
    for (const auto& c: orig) {
        if (c != target) {
            buf += c;
        }
    }
    return buf;
}

std::string remove(const std::string& orig, const std::string& target) {
    if (target.empty()) { return orig; }

    std::string buf;
    buf.reserve(orig.length());
    size_t pos = 0;
    while (pos < orig.length()) {
        if (orig.substr(pos, target.length()) == target) {
            pos += target.length();
        }
        else {
            buf += orig[pos];
            ++pos;
        }
    }
    return buf;
}

std::string replace(std::string orig, char from, char to)
{
    for (size_t i=0; i<orig.length(); ++i) {
        if (orig[i] == from) { orig[i] = to; }
    }
    return orig;
}

std::string replace(const std::string& orig, const std::string& from, const std::string& to)
{
    if (orig.empty()) { return ""; }

    std::string result;
    size_t pos = 0;
    while (pos < orig.length()) {
        if (orig.substr(pos, from.length()) == from) {
            result.append(to);
            pos += from.length();
        }
        else {
            result += orig[pos];
            ++pos;
        }
    }
    return result;
}

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

std::string tolower(const std::string& orig) {
    std::string lower = orig;
    for (size_t i = 0; i < lower.length(); ++i) {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

std::string toupper(const std::string& orig) {
    std::string upper = orig;
    for (size_t i = 0; i < upper.length(); ++i) {
        upper[i] = toupper(upper[i]);
    }
    return upper;
}
