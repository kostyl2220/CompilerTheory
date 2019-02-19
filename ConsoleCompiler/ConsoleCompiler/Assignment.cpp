#include "pch.h"
#include "Element.h"
#include "Assignment.h"
#include "Exceptions.h"
#include "Program.h"

Variable Assignment::run(Blackboard& blackboard) throw(ExceptionBase) {
	int index = -1; 
	for (size_t i = 0; i < blackboard.vars.size(); ++i)
		if (blackboard.vars[i].getName() == varName)
		{
			index = i;
			break;
		}
	if (index == -1)
		throw VariableNotFoundException("Using undeclared variable", line, column);
	Variable temp = rValue->run(blackboard);
	blackboard.vars[index].setValue(temp.getValue());
	blackboard.vars[index].setType(temp.getType());
	return temp;
}

string Assignment::getName() {
	return varName;
}