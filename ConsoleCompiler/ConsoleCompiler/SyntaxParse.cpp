#include "pch.h"
#include "SyntaxParse.h"
#include "Program.h"
#include "parse.h"
#include "Assignment.h"
#include "Condition.h"
#include "Loops.h"
#include "CreateVariable.h"
#include "StandartFunction.h"
#include "Function.h"
#include "HelperFuncs.h"


std::string reserved[] = {
	"var", "for", "while", "do", "if", "else", "out", "in", "func", "code"
};
static int COUNT_OF_RESERVED = 10;

bool isReserved(std::string const& word) {
	for (int i = 0; i < COUNT_OF_RESERVED; ++i)
		if (word == reserved[i]) return true;
	return false;
}

bool NeedToBeClosed(Element* head)
{
	return head->getType() == LEAF
		|| head->getType() == ASSIGN
		|| head->getType() == CREATE
		|| head->getType() == NODE
		|| head->getType() == FUNC;
}

//1. Extend assign
//2. Look into adding two blocks

Element* totalParse(Element* head, vector<std::string> const& code, size_t &i, size_t &j, bool brackets, char ch) throw(ExceptionBase) {
	while (!endOfCode(code, i)) {
		while (code[i][j] == ' ' || //skip spaces
			code[i][j] == '\0' || code[i][j] == '\t') {
			incCode(code, i, j);
			if (endOfCode(code, i)) return head;
		}
		if (code[i][j] == ';') { //stop on delimeter
			return head;
		}
		else if (code[i][j] == '(') { //more for trash
			incCode(code, i, j);
			Program* prog = new Program(BRACK);
			while (code[i][j] != ')')
			{
				prog->addCommand(totalParse(new Element, code, i, j, true));
				if (endOfCode(code, i))
					throw CompileExeption("Closing bracket not found", i, j);
				if (nextChar(code, i, j) == ';')  {
					incCode(code, i, j);
					if (nextChar(code, i, j) == ')')
						throw CompileExeption("Point&", i, j);
				}
			}
			//prog->setValue();
			delete head;
			head = prog;
			incCode(code, i, j);

		}
		else if (code[i][j] == ')')//trash
		{
			if (!brackets)
				throw CompileExeption("Closed bracket", i, j);
			//incCode(code, i, j);
			return head;
		}
		else if (code[i][j] == '=') {//new assignment
			incCode(code, i, j);
			int remI = i, remJ = j;
			head = new Assignment(head->getValue(), totalParse(new Element, code, i, j, brackets), remI, remJ);
		}		
		else if (code[i][j] == '{') {//block of code
			if (NeedToBeClosed(head))
				throw CompileExeption("Unexpected token", i, j);
			else if (head->getType() != EMPTY)
				return head;

			incCode(code, i, j);
			Program* prog = new Program();
			while (code[i][j] != '}')
			{
				prog->addCommand(totalParse(new Element, code, i, j, false));
				if (endOfCode(code, i))
				{
					throw CompileExeption("Unclosed bracket", i, j);
				}
				if (nextChar(code, i, j) == ';') 
				{
					incCode(code, i, j);
				}
				while (!endOfCode(code, i) && code[i][j] == ' ' || //skip spaces
					code[i][j] == '\0' || code[i][j] == '\t') {
					incCode(code, i, j);
				}
				if (endOfCode(code, i))
				{
					throw CompileExeption("Unclosed bracket", i, j);
				}
			}
			head = prog;
			incCode(code, i, j);
		}
		else if (code[i][j] == '}')
		{
			if (head->getType() != PROG)
			{
				throw CompileExeption("Unexpected closed figure bracket", i, j);
			}
			return head;
		}
		else if (code[i][j] == '+' || code[i][j] == '-' //arythmetic parse
			|| code[i][j] == '*' || code[i][j] == '/'
			|| code[i][j] == '<' || code[i][j] == '>')
		{
			head = parse(head, code, i, j, brackets, ch);
		}
		else
		{

			if (NeedToBeClosed(head))
				throw CompileExeption("Unexpected token", i, j);
			else if (head->getType() != EMPTY)//for other en of command(if not empty)
				return head;

			string temp = nextWord(code, i, j);//read token

			if (isReserved(temp))//if reserved look for it
			{
				if (temp == "var") {//create var
					delete head;
					int remI = i, remJ = j;
					head = new CreateVariable(totalParse(new Element, code, i, j, brackets), remI, remJ);
				}
				else if (temp == "if") {//condition
					Element *cond, *exec, *elseClause;
					if (nextChar(code, i, j) == '(') {//must have brackets
						incCode(code, i, j);
						cond = totalParse(new Element, code, i, j, true);//and cond
						if (code[i][j] == ')')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token in IF", i, j);
					}
					else throw CompileExeption("Unexpected token in IF", i, j);
					exec = totalParse(new Element, code, i, j, brackets);//after exec part
					delete head;
					if (exec->getType() == PROG && //TODO FIX
						nextChar(code, i, j) == ';') //on cur line
						head = new Condition(cond, exec, new Element);
					else {
						if (exec->getType() != PROG)
							if (nextChar(code, i, j) != ';')//for blocks and single commands
								throw CompileExeption("Unexpected token if IF", i, j);
							else incCode(code, i, j);

						string temp = nextWord(code, i, j);
						if (temp == "else")
							elseClause = totalParse(new Element, code, i, j, brackets);
						else {
							j -= temp.length();
							elseClause = new Element("0");
						}
						head = new Condition(cond, exec, elseClause);
					}
				}
				else if (temp == "while") {//while loop
					Element *cond, *exec;
					if (nextChar(code, i, j) == '(') {//must have brackets
						incCode(code, i, j);
						cond = totalParse(new Element, code, i, j, true);
						if (code[i][j] == ')')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token in WHILE", i, j);
					}
					else throw CompileExeption("Unexpected token in WHILE", i, j);
					exec = totalParse(new Element, code, i, j, brackets);
					delete head;
					head = new WhileLoop(cond, exec);
				}
				else if (temp == "for") {
					Element *first, *cond, *rep, *body;
					if (nextChar(code, i, j) == '(') {//must have brackets
						incCode(code, i, j);
						first = totalParse(new Element, code, i, j, brackets);
					}
					else throw CompileExeption("Unexpected token in FOR", i, j);


					if (nextChar(code, i, j) != ';')
						throw CompileExeption("Unexpected token in FOR", i, j);
					else incCode(code, i, j);

					cond = totalParse(new Element, code, i, j, brackets);

					if (nextChar(code, i, j) != ';')
						throw CompileExeption("Unexpected token in FOR", i, j);
					else incCode(code, i, j);

					rep = totalParse(new Element, code, i, j, true);
					if (code[i][j] == ')')
						incCode(code, i, j);
					else throw CompileExeption("Unexpected token in FOR", i, j);

					body = totalParse(new Element, code, i, j, brackets);
					delete head;
					head = new ForLoop(first, cond, rep, body);

				}
				else if (temp == "do") {
					delete head;

					Element *cond, *exec;
					exec = totalParse(new Element, code, i, j, brackets);

					//if command was single 
					if (exec->getType() != PROG) //TODO for scala case
						if (nextChar(code, i, j) != ';')
							throw CompileExeption("Unexpected token in DO WHILE", i, j);
						else incCode(code, i, j);

					string temp = nextWord(code, i, j);

					if (temp == "while") {
						if (nextChar(code, i, j) == '(') {//must have brackets
							incCode(code, i, j);
							cond = totalParse(new Element, code, i, j, true);
							if (code[i][j] == ')')
								incCode(code, i, j);
							else throw CompileExeption("Unexpected token in DO WHILE", i, j);
						}
						else throw CompileExeption("Unexpected token in DO WHILE", i, j);
					}
					else {
						j -= temp.length();
						throw CompileExeption("Unexpected token in DO WHILE", i, j);
					}
					head = new DoWhileLoop(cond, exec);
				}
				else if (temp == "else") {//cant reach cause predicted in IF
					throw CompileExeption("Unexpected token", i, j);
				}
				else if (temp == "out") {//reserved standart function
					vector<Element*> variables;
					Element* temp;
					if (nextChar(code, i, j) == '(') {
						incCode(code, i, j);
						temp = totalParse(new Element, code, i, j, true);
						if (code[i][j] == ')')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token in OUT", i, j);
						variables.push_back(temp);
					}
					else throw CompileExeption("Unexpected token in OUT", i, j);
					head = new StandartFunction("out", variables);
				}
				else if (temp == "in") {//reserved unworked function
					vector<Element*> variables;
					if (nextChar(code, i, j) == '(') {
						incCode(code, i, j);
						if (nextChar(code, i, j) == ')')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token in IN", i, j);
					}
					else throw CompileExeption("Unexpected token in IN", i, j);
					head = new StandartFunction("in", variables);
				}
				else if (temp == "code") {//reserved unworked function
					vector<Element*> variables;
					if (nextChar(code, i, j) == '(') {
						incCode(code, i, j);
						if (nextChar(code, i, j) == ')')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token in IN", i, j);
					}
					else throw CompileExeption("Unexpected token in IN", i, j);
					head = new StandartFunction("code", variables);
				}
				else if (temp == "func") {
					string  funcName = nextWord(code, i, j);
					vector<string> paramNames;
					if (nextChar(code, i, j) == '(') {
						incCode(code, i, j);
						while (code[i][j] != ')') {
							paramNames.push_back(nextWord(code, i, j));
							if (endOfCode(code, i))
								throw CompileExeption("Unexpected end of code", i, j);
							if (nextChar(code, i, j) == ';')
								incCode(code, i, j);
						}
						incCode(code, i, j);
						head = new FunctionBody(funcName, paramNames, totalParse(new Element, code, i, j, true));
						/*if (nextChar(code, i, j) == ';')
							incCode(code, i, j);
						else throw CompileExeption("Unexpected token on FUNCTION", i, j);*/
					}
					else throw CompileExeption("Unexpected token in OUT", i, j);
				}
			}
			else if (nextChar(code, i, j) == '(') {//function
				vector<Element*> vars;
				incCode(code, i, j);
				while (nextChar(code, i, j) != ')') {
					vars.push_back(totalParse(new Element, code, i, j, true));
					if (endOfCode(code, i))
						throw CompileExeption("Unexpected end of code", i, j);
					if (nextChar(code, i, j) == ';')
						incCode(code, i, j);
				}
				incCode(code, i, j);
				head = new FunctionCall(temp, vars);
			}
			else {//single token
				delete head;
				head = new Element(temp, i, j - temp.length());
			}
		}
	}
	if (NeedToBeClosed(head))
		throw CompileExeption("Unexpected end of code", i - i, code[i - i].size() - 1);
	else return head;
}