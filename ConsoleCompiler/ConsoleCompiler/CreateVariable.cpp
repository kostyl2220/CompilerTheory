#include "pch.h"
#include "CreateVariable.h"
#include "Exceptions.h"
#include "Variable.h"

Variable CreateVariable::run(Blackboard& blackboard) throw(ExceptionBase) {
	for (size_t i = 0; i < blackboard.vars.size(); ++i)
		if (blackboard.vars[i].getName() == varName)
			throw VariableExistsException("Redeclaration of variable", line, column);
	blackboard.vars.insert(blackboard.vars.begin(), Variable("0", varName.c_str())); // TODO rewrite
	return assign->run(blackboard);
}


