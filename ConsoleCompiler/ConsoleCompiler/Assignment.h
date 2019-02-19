#pragma once
#include "Variable.h"

class Assignment : public Element {
private:
	string varName;
	Element* rValue;

public:
	Assignment(string nm, Element* rVal, int ln = 0, int col = 0) : Element(ASSIGN, nm, ln, col), varName(nm), rValue(rVal) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~Assignment(){
		delete rValue;
	}

	string getName();
};