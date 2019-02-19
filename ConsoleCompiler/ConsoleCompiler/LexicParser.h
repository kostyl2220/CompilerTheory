#include <string>
#include <vector>

enum class TokenType
{
	IF,
	ELSE,
	FOR,
	WHILE,
	DO,
	FUNC,
	IN,
	OUT,
	OPEN_BRACKET,
	CLOSED_BRACKET,
	OPEN_F_BRACKER,
	CLOSED_F_BRACKET,
	VAR,
	ASSIGNMENT,
	DOT_AND_COMMA,
	VALUE,
	PLUS,
	MINUS,
	DIVIDE,
	MULTIPLY,
	GREATER,
	LESS,
	STRING,
	COMMA,
	DOT
};

struct Token
{
	TokenType type;
	std::string value;

	Token(TokenType t) : type(t) {}
	Token(TokenType t, std::string const& v) : type(t), value(v) {}
};

std::vector<Token> LexicalParse(std::vector<std::string> const& code);