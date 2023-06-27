#include "stringutils.h"


/**
 * Join a vector of strings into a single string.
 * 
 * @param parts The vector of substrings to join.
 * @return A string consisting of the joined substrings.
*/
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

/**
 * Join a vector of strings into a single string.
 * 
 * @param parts The vector of substrings to join.
 * @param delim A single character to be used as a delimiter between each substring.
 * @return A string consisting of the joined substrings joined by the delimiting character.
 */
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

/**
 * Join a vector of strings into a single string.
 * 
 * @param parts The vector of substrings to join.
 * @param delim A substring o be used as a delimiter between each substring.
 * @return A string consisting of the joined substrings joined by the delimiting substring.
 */
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

/**
 * Remove all instances of a character
 * 
 * @param orig The original input string. 
 * @param target A character to be removed from the input string.
 * @return A string consisting of the joined substrings.
*/
std::string remove(const std::string& orig, char target) 
{
    std::string buf;
    buf.reserve(orig.length());
    for (const auto& c: orig) {
        if (c != target) {
            buf += c;
        }
    }
    return buf;
}

/**
 * Remove all instances of a substring
 * 
 * @param orig The original input string. 
 * @param sub A substring to be removed from the input string.
 * @return A string consisting of the joined substrings.
*/
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

/**
 * Replace all occurrences of a character with a different character.
 * 
 * @param orig The original input string.
 * @param from The character to be replaced.
 * @param to The character to be used as a replacement.
 * @return A modified copy of the original string after character 
 *         replacement has been performed.
 */
std::string replace(std::string orig, char from, char to)
{
    for (size_t i=0; i<orig.length(); ++i) {
        if (orig[i] == from) { orig[i] = to; }
    }
    return orig;
}

/**
 * Replace all occurrences of a substring with a different substring.
 * 
 * @param orig The original input string.
 * @param from The substring to be replaced.
 * @param to The substring to be used as a replacement.
 * @return A modified copy of the original string after substring 
 *         replacement has been performed.
 */
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

/**
 * Split a string at each occurrence of a whitespace character.
 * Sequential whitespaces are treated as a single delimiter.
 * 
 * @param orig The string to be split.
 * @return A vector of substrings.
 */
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

/**
 * Split a string at each occurrence of a character.
 * Sequential delimiting characters are treated as a single delimiter.
 * 
 * @param orig The string to be split.
 * @param delim A character to be used as a delimiter.
 * @return A vector of substrings.
 */
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

/**
 * Split a string at each occurrence of a substring.
 * Sequential delimiting substrings are treated as a single delimiter.
 * 
 * @param orig The string to be split.
 * @param delim A delimiter to be used as a delimiter.
 * @return A vector of substrings.
 */
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

/**
 * Strip whitespace from the beginning  of a string.
 * 
 * @param orig The string to be stripped.
 * @return A copy of the input string with leading whitespace removed.
 */
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

/**
 * Strip a character from the beginning  of a string.
 * 
 * @param orig The string to be stripped.
 * @param delim The character to be removed from the input string.
 * @return A copy of the input string with leading delimiters removed.
 */
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

/**
 * Strip a substring from the beginning  of a string.
 * 
 * @param orig The string to be stripped.
 * @param delim The substring to be removed from the input string.
 * @return A copy of the input string with leading delimiters removed.
 */
std::string lstrip(const std::string& orig, const std::string& delim)
{
    if (delim.empty()) { return orig; }
    size_t start = 0;
    while(orig.substr(start, delim.length()) == delim && start < orig.length()) {
        start += delim.length();
    }
    return start == 0 ? orig : orig.substr(start, orig.length());
}

/**
 * Strip whitespace from the end of a string.
 * 
 * @param orig The string to be stripped.
 * @return A copy of the input string with trailing whitespace removed.
 */
std::string rstrip(const std::string& orig)
{
    size_t pos = orig.find_last_not_of(" \t\n");
    return pos == std::string::npos ? "" : orig.substr(0, pos+1);
}

/**
 * Strip a character from the beginning of a string.
 * 
 * @param orig The string to be stripped.
 * @param delim The character to be removed from the input string.
 * @return A copy of the input string with leading delimiters removed.
 */
std::string rstrip(const std::string& orig, char delim)
{
    size_t pos = orig.find_last_not_of(delim);
    return pos == std::string::npos ? "" : orig.substr(0, pos+1);
}

/**
 * Strip a substring from the beginning of a string.
 * 
 * @param orig The string to be stripped.
 * @param delim The substring to be removed from the input string.
 * @return A copy of the input string with leading delimiters removed.
 */
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

/**
 * Remove leading and trailing whitespace from the input string.
 * 
 * @param orig The input string to be stripped.
 * @return A copy of the input string with leading and trailing whitespace removed.
 */
std::string strip(const std::string& orig) {
    return rstrip(lstrip(orig));
}

/**
 * Remove leading and trailing delimiters from the input string.
 * 
 * @param orig The input string to be stripped.
 * @param delim A delimiting character to be stripped.
 * @return A copy of the input string with leading and trailing delimiters removed.
 */
std::string strip(const std::string& orig, char delim) {
    return rstrip(lstrip(orig, delim), delim);
}

/**
 * Remove leading and trailing delimiters from the input string.
 * 
 * @param orig The input string to be stripped.
 * @param delim A delimiting substring to be stripped.
 * @return A copy of the input string with leading and trailing delimiters removed.
 */
std::string strip(const std::string& orig, const std::string& delim) {
    return rstrip(lstrip(orig, delim), delim);
}

/**
 * Convert a string to lowercase.
 * 
 * @param orig The input string.
 * @return A lowercase copy of the input string.
 */
std::string tolower(const std::string& orig) {
    std::string lower = orig;
    for (size_t i = 0; i < lower.length(); ++i) {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

/**
 * Convert a string to uppercase.
 * 
 * @param orig The input string.
 * @return An uppercase copy of the input string.
 */
std::string toupper(const std::string& orig) {
    std::string upper = orig;
    for (size_t i = 0; i < upper.length(); ++i) {
        upper[i] = toupper(upper[i]);
    }
    return upper;
}
