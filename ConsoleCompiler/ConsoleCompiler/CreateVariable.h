#pragma once
#include "Variable.h"
#include <string>

class CreateVariable : public Element {
private:
	Element* assign;
	string varName;
public:
	CreateVariable(Element* ass, int ln = 0, int col = 0) : Element(CREATE, "", ln, col), assign(ass) {
		varName = ass->getValue();
	};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~CreateVariable() {
		delete assign;
	}

};