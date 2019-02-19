#include "pch.h"
#include "Loops.h"
#include <vector>

Variable ForLoop::run(Blackboard& blackboard) throw(ExceptionBase) {
	size_t const startVarCount = blackboard.vars.size();
	start->run(blackboard);
	Variable temp;
	while (cond->run(blackboard).isTrue()) {
		temp = body->run(blackboard);
		rep->run(blackboard);
	}
	size_t const difference = blackboard.vars.size() - startVarCount;
	for (size_t i = 0; i < difference; ++i)//delete local vars
	{
		blackboard.vars.erase(blackboard.vars.begin());
	}
	return temp;
}


Variable WhileLoop::run(Blackboard& blackboard) throw(ExceptionBase) {
	size_t const startVarCount = blackboard.vars.size();
	Variable temp;
	while (cond->run(blackboard).isTrue()) {
		temp = body->run(blackboard);
	}
	size_t const difference = blackboard.vars.size() - startVarCount;
	for (size_t i = 0; i < difference; ++i)//delete local vars
	{
		blackboard.vars.erase(blackboard.vars.begin());
	}
	return temp;
}


Variable DoWhileLoop::run(Blackboard& blackboard) throw(ExceptionBase){
	size_t const startVarCount = blackboard.vars.size();
	Variable temp;
	do {
		temp = body->run(blackboard);
	} while (cond->run(blackboard).isTrue());

	size_t const difference = blackboard.vars.size() - startVarCount;
	for (size_t i = 0; i < difference; ++i)//delete local vars
	{
		blackboard.vars.erase(blackboard.vars.begin());
	}
	return temp;
}
