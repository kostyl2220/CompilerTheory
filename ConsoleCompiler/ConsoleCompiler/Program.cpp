#include "pch.h"
#include "Program.h"
#include "SyntaxParse.h"
#include "Node.h"
#include "Assignment.h"
#include "Condition.h"
#include "Loops.h"
#include "CreateVariable.h"
#include "StandartFunction.h"
#include "Function.h"
#include "HelperFuncs.h"

Program::Program() : Element(PROG, "") {};

Variable Program::run(Blackboard& blackboard) throw(ExceptionBase) {
	int remSize = blackboard.vars.size();//remember size of vars
	
	if (body.empty())
	{
		return Variable();
	}

	for (size_t i = 0; i < body.size() - 1; ++i) {
		body[i]->run(blackboard);//add local vars
	}
	Variable el(body[body.size() - 1]->run(blackboard));

	this->vars = blackboard.vars;
	remSize = blackboard.vars.size() - remSize;
	for (size_t i = 0; i < remSize; ++i)//delete local vars
	{
		blackboard.vars.erase(blackboard.vars.begin());
	}
	return el;
}

void Program::addCommand(Element* comm) throw(ExceptionBase){
	body.push_back(comm);
}

void Program::outVarList(ostream* output) {
	*output << std::endl;
	for (size_t i = 0; i < vars.size(); ++i)
	{
		*output << vars[i].getName() << " = " << vars[i].getValue() << std::endl;
	}
}

void Program::runProgram(ostream* output) throw(ExceptionBase){
	Blackboard blackboard;
	blackboard.stream = output;
	run(blackboard);
}

void Program::addCode(vector<std::string> const& code) throw(ExceptionBase) {
	Element* head;
	size_t i = 0, j = 0;
	while (!endOfCode(code, i)) {
			head = totalParse(new Element, code, i, j, false);//parse command
			if (!endOfCode(code, i) && code[i][j] == ';') incCode(code, i, j);//while not end of code skip delimeter
			if (head->getType() != EMPTY)
			{
				this->addCommand(head);//add code
			}
		} 
}

void Program::setValue() {
	Element::setValue(body.back()->getValue());
}