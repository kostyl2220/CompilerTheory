#include "pch.h"
#include "Node.h"

Variable Node::run(Blackboard& blackboard) throw(ExceptionBase){
	if (value[0] == '+')
		return left->run(blackboard) + right->run(blackboard);
	if (value[0] == '-')
		return left->run(blackboard) - right->run(blackboard);
	if (value[0] == '*')
		return left->run(blackboard) * right->run(blackboard);
	if (value[0] == '/')
		return left->run(blackboard) / right->run(blackboard);
	if (value[0] == '>')
		return left->run(blackboard) > right->run(blackboard);
	if (value[0] == '<')
		return left->run(blackboard) < right->run(blackboard);
	/*if (value[0] == '=')
		return left->run(blackboard) == right->run(blackboard);*/
	return Variable();
}

