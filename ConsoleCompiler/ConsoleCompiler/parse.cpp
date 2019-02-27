#include "pch.h"
#include "parse.h"
#include "Exceptions.h"
#include "HelperFuncs.h"

const int N = 100;
int count_of_brackets = 0;
bool error = false;

vector<vector<char>> priors = {
	{ '/', '*' },
	{ '+', '-' },
	{ '>', '<', '=', 'n' },
	{ '|', '&' }
};

bool higherInPriority(char ch, char ch1) {
	size_t prior1 = 50, prior2 = 50;
	for (size_t i = 0; i < priors.size(); ++i)
		for (size_t j = 0; j < priors[i].size(); ++j) {
			if (ch == priors[i][j]) prior1 = i;
			if (ch1 == priors[i][j]) prior2 = i;
		}
	return prior1 < prior2;
}

Element* parse(Element *head, vector<std::string> const& code, size_t &i, size_t &j, bool bracket, char ch) {
	while (!endOfCode(code, i)) {
		while (code[i][j] == ' ' ||
			code[i][j] == '\0' || code[i][j] == '\t') {
			incCode(code, i, j);
			if (endOfCode(code, i)) return head;
		}
		if (code[i][j] == ';') {
			return head;
		}
		if (code[i][j] == '(') {
			throw CompileExeption("Never enter", i, j);
			incCode(code, i, j);
			++count_of_brackets;
			head = totalParse(head, code, i, j, true, ')');
			if (code[i][j] != ')') {
				throw CompileExeption("Unclosed bracket", i, j);
			}
			incCode(code, i, j);
		}
		else if (code[i][j] == ')') {
			if (!bracket)
			{
				throw CompileExeption("Unexpected closed bracket", i, j);
			}
			return head;
		}
		else if (code[i][j] != '+' && 
			(code[i][j] != '-'
			|| code[i][j] == '-' && (ch != ' ' || ch != ')'))
			&& code[i][j] != '*' && code[i][j] != '/'
			&& code[i][j] != '<' && code[i][j] != '>'
			&& code[i][j] != '{' && code[i][j] != '}') 
			{
				char chr = code[i][j];
				string temp;
				if (chr == '-') {
					incCode(code, i, j);
					temp = chr + nextWord(code, i, j);
				}
				else temp = nextWord(code, i, j);
				head->setValue(temp);
				if (ch != ' ' &&
					higherInPriority(ch, nextChar(code, i, j)) &&
					ch != ')') return head;
			}
		else if (code[i][j] == '+') {
			if (ch != ' ' && higherInPriority(ch, code[i][j])) return head;
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket, '+');
			head = new Node("+", head, temp, OP);
		}
		else if (code[i][j] == '*') {
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket, '*');
			head = new Node("*", head, temp, OP);
		}
		else if (code[i][j] == '/') {
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket,'*');
			head = new Node("/", head, temp, OP);
		}
		else if (code[i][j] == '-') {
			if (ch != ' ' && higherInPriority(ch, code[i][j])) return head;
			if (ch != ' ' && ch != ')') {
				
			}
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket, '-');
			head = new Node("-", head, temp, OP);
		}
		else if (code[i][j] == '>') {
			if (ch != ' ' && higherInPriority(ch, code[i][j])) return head;
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket, '>');
			head = new Node(">", head, temp, OP);
		}
		else if (code[i][j] == '<') {
			if (ch != ' ' && higherInPriority(ch, code[i][j])) return head;
			Element* temp = new Element();
			incCode(code, i, j);
			temp = totalParse(temp, code, i, j, bracket, '<');
			head = new Node("<", head, temp, OP);
		}
		else return head;
	}
	return head;
}
