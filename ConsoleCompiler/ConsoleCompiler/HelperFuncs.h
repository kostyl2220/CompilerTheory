#pragma once
#include <vector>
#include <string>

void incCode(std::vector<std::string> const& code, size_t &i, size_t &j); //in not end of line inc col. else inc line
bool endOfCode(std::vector<std::string> const& code, size_t i);
char nextChar(std::vector<std::string> const& code, size_t &i, size_t&j); //next char. not equal to space
std::string nextWord(std::vector<std::string> const& code, size_t& i, size_t& j); //next valuable word