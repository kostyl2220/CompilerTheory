#pragma once
#include  <string>
#include "Element.h"

bool NeedToBeClosed(Element* head);
bool isReserved(std::string const& word); //check if word is reserved
Element* totalParse(Element* head, vector<std::string> const& code, size_t &i, size_t &j, bool brackets, char ch = ' ') throw(ExceptionBase);//parse of command