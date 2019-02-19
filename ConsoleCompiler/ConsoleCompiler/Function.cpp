#include "pch.h"
#include "Function.h"


Variable FunctionBody::run(Blackboard& blackboard) throw(ExceptionBase) {
	blackboard.funcs.push_back(*this);
	return Variable("0", "Nothing");
}

Variable FunctionCall::run(Blackboard& blackboard) throw(ExceptionBase) {
	for (size_t i = 0; i < blackboard.funcs.size(); ++i) {
		if (blackboard.funcs[i].getValue() == this->getValue()) {
			vector<string> args = blackboard.funcs[i].getParameters();
			if (args.size() != this->params.size())
				throw CompileExeption("Parameters mismatch", line, column);
			vector<Variable> variables;
			for (size_t j = 0; j < params.size(); ++j) {
				variables.push_back(params[j]->run(blackboard));
				variables[j].setName(args[j]);
			}
			Blackboard newB{ variables, blackboard.funcs, blackboard.stream };
			return blackboard.funcs[i].getBody()->run(newB);
		}
	}
	throw CompileExeption("Function not found", line, column);
}

Element* FunctionBody::getBody() const {
	return this->body;
}

vector<string> FunctionBody::getParameters() const {
	return params;
}