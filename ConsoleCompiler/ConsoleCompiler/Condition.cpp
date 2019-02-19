#include "pch.h"
#include "Condition.h"

Variable Condition::run(Blackboard& blackboard) throw(ExceptionBase) {
	if (cond->run(blackboard).isTrue())
		return exec->run(blackboard);
	else return elseClause->run(blackboard);
}
