#pragma once
#include <iostream>
#include "Element.h"
#include "Variable.h"

class Program : public Element {//programs and blocks
private:
	std::vector<Variable> vars;
	std::vector<Element*> body;

public:
	Program();
	Program(ElemType el, int ln = 0, int col = 0) : Element(BRACK, "", ln, col) {};
	Variable run(Blackboard& blackboard);

	//for main program
	Variable runProgram(ostream* ostream) throw(ExceptionBase);

	void addCommand(Element* comm) throw(ExceptionBase);

	void outVarList(ostream* output);

	void addCode(vector<std::string> const& code) throw(ExceptionBase);

	void setValue();
};

