#include "pch.h"
#include "HelperFuncs.h"
#include "Exceptions.h"
#include <locale>

void incCode(std::vector<std::string> const& code, size_t &i, size_t &j) {
	if (j == (code[i].size()))
	{
		++i;
		j = 0;
	}
	else
	{
		++j;
	}
	while (!endOfCode(code, i) && code[i].empty())
	{
		++i;
		j = 0;
	}
}

bool endOfCode(std::vector<std::string> const& code, size_t i) {
	if (i >= code.size()) return true;
	return false;
}


char nextChar(std::vector<std::string> const& code, size_t &i, size_t&j) {
	while (!endOfCode(code, i) &&
		code[i][j] == ' ') incCode(code, i, j);
	if (endOfCode(code, i))
		return '\0';
	return code[i][j];
}

std::string nextWord(std::vector<std::string> const& code, size_t& i, size_t& j) {
	std::string temp;
	while (!endOfCode(code, i) &&
		code[i][j] == ' ') incCode(code, i, j);
	if (endOfCode(code, i))
		return "";
	int k = 0;
	if (code[i][j] == '"') {//if its string
		temp += code[i][j];
		incCode(code, i, j);
		if (endOfCode(code, i))
			throw CompileExeption("Unexpected end of code is string", i, j);
		while (code[i][j] != '"') {//while dont close
			temp += code[i][j];//read char
			incCode(code, i, j);
			if (endOfCode(code, i))
				throw CompileExeption("Unexpected end of code is string", i, j);
		}
		temp += code[i][j];
		incCode(code, i, j);
		return temp;
	}
	while (code[i][j] != '\0' && //else while not op char
		code[i][j] != ' ' && code[i][j] != '=' &&
		code[i][j] != ';' &&
		code[i][j] != '+' && code[i][j] != '-'
		&& code[i][j] != '*' && code[i][j] != '/'
		&& code[i][j] != '(' && code[i][j] != ')'
		&& code[i][j] != '{' && code[i][j] != '}') {
		temp += code[i][j];
		++j;
		++k;
	}
	if (j == (code[i].size())) incCode(code, i, j);
	//temp += '\0';
	if (!IsWordValid(temp))
	{
		throw CompileExeption("Invalid word", i, j);
	}

	return temp;
}

bool IsWordValid(std::string const& word)
{
	auto pos = word.find_first_of('.');
	if (!isdigit(word[0]))
	{
		return pos == std::string::npos;
	}

	if (pos != word.find_last_of('.'))
	{
		return false;
	}

	for (char const ch : word)
	{
		if (!isdigit(ch) && ch != '.')
		{
			return false;
		}
	}
	return true;
}