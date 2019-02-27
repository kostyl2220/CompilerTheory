#include "pch.h"
#include "LexicParser.h"
#include <map>
#include "HelperFuncs.h"

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

static std::string tokenNames[] =
{
	"IF",
	"ELSE",
	"FOR",
	"WHILE",
	"DO",
	"FUNC",
	"IN",
	"OUT",
	"OPEN_BRACKET",
	"CLOSED_BRACKET",
	"OPEN_F_BRACKER",
	"CLOSED_F_BRACKET",
	"VAR",
	"ASSIGNMENT",
	"DOT_AND_COMMA",
	"VALUE",
	"PLUS",
	"MINUS",
	"DIVIDE",
	"MULTIPLY",
	"GREATER",
	"LESS",
	"STRING",
	"COMMA",
	"DOT",
};

bool IsOperation(Token const& token)
{
	return token.type >= TokenType::PLUS && token.type < TokenType::STRING;
}

void PrintTokens(std::vector<Token> const& tokens, std::ostream* ostream)
{
	for (auto const& token : tokens)
	{
		*ostream << tokenNames[(size_t)token.type] << " ";
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
			incCode(code, i, j);
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
		
	}
	return tokens;
}