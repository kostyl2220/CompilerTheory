#pragma once
#include "Variable.h"

class Condition : public Element  {
private:
	Element *cond, *exec, *elseClause;
public:
	Condition(Element* Ocond, Element* Oexec, Element* OelseClause, int ln = 0, int col = 0) :
		Element(COND, "", ln, col), cond(Ocond), exec(Oexec), elseClause(OelseClause) {}

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~Condition() {
		delete cond, exec, elseClause;
	}
};