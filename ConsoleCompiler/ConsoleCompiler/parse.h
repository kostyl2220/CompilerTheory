#pragma once
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <algorithm>

#include "SyntaxParse.h"
#include "Element.h"
#include "Node.h"

using namespace std;

bool higherInPriority(char ch, char ch1);
Element* parse(Element *head, vector<std::string> const& code, size_t &i, size_t &j, bool bracket, char ch);