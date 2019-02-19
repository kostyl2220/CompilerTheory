#include "pch.h"
#include "StandartFunction.h"
#include "Exceptions.h"

Variable StandartFunction::run(Blackboard& blackboard) throw(ExceptionBase){
	if (value == "out") {
		for (size_t i = 0; i < params.size(); ++i)
			*(blackboard.stream) << params[i]->run(blackboard).getValue();
	}
	if (value == "in") {

	}
	return Variable("0", "rValue", "int");
}

