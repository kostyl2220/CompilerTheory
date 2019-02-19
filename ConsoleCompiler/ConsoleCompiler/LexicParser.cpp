#include "pch.h"
#include "LexicParser.h"
#include <map>
#include "Exceptions.h"

static std::map<char, TokenType> mapOfTokens =
{
	{';', TokenType::DOT_AND_COMMA},
	{'(', TokenType::OPEN_BRACKET},
	{')', TokenType::CLOSED_BRACKET},
	{'{', TokenType::OPEN_F_BRACKER},
	{'}', TokenType::CLOSED_F_BRACKET},
	{'=', TokenType::ASSIGNMENT},
	{'+', TokenType::PLUS},
	{'-', TokenType::MINUS},
	{'/', TokenType::DIVIDE},
	{'*', TokenType::MULTIPLY},
	{'<', TokenType::LESS},
	{'>', TokenType::GREATER},
	{',', TokenType::COMMA},
	{'.', TokenType::DOT}
};

static std::map<std::string, TokenType> mapOfReserved =
{
	{"var", TokenType::VAR},
	{"if", TokenType::IF},
	{"while", TokenType::WHILE},
	{"for", TokenType::FOR},
	{"do", TokenType::DO},
	{"else", TokenType::ELSE},
	{"out", TokenType::OUT},
	{"in", TokenType::IN},
	{"func", TokenType::FUNC}
};

namespace
{
	void incCode(std::vector<std::string> const& code, size_t &i, size_t &j) {
		if (j < (code[i].size() - 1)) ++j;
		else {
			++i;
			j = 0;
		}
	}

	bool endOfCode(std::vector<std::string> const& code, size_t i) {
		if (i >= code.size()) return true;
		return false;
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
		return temp;
	}
}

std::vector<Token> LexicalParse(std::vector<std::string> const& code)
{
	size_t i = 0;
	size_t j = 0;
	std::vector<Token> tokens;
	while (!endOfCode(code, i))
	{
		while (code[i][j] == ' ' //skip spaces
			|| code[i][j] == '\0')
		{
			incCode(code, i, j);
			if (endOfCode(code, i))
			{
				return tokens;
			}
		}
		auto iter = mapOfTokens.find(code[i][j]);
		if (iter != mapOfTokens.end())
		{
			tokens.push_back(Token(iter->second));
		}
		else
		{
			std::string temp = nextWord(code, i, j);//read token

			auto iter = mapOfReserved.find(temp);
			if (iter != mapOfReserved.end())
			{
				tokens.push_back(Token(iter->second));
			}
			else
			{//single token
				tokens.push_back(Token(temp[0] == '"' ? TokenType::STRING : TokenType::VALUE, temp));
			}
		}
		incCode(code, i, j);
	}
	return tokens;
}