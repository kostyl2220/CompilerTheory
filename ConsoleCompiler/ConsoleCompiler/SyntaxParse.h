#pragma once
#include  <string>
#include "Element.h"

bool isReserved(std::string const& word); //check if word is reserved
void incCode(vector<std::string>const& code, size_t &i, size_t &j); //in not end of line inc col. else inc line
bool endOfCode(vector<std::string>const& code, size_t i);
char nextChar(vector<std::string>const& code, size_t&i, size_t&j);//next char. not equal to space
string nextWord(vector<std::string>const& code, size_t &i, size_t&j);//next valuable word
Element* totalParse(Element* head, vector<std::string> const& code, size_t &i, size_t &j, bool brackets, char ch = ' ') throw(ExceptionBase);//parse of command