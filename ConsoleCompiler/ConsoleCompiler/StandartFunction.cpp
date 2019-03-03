#include "pch.h"
#include "StandartFunction.h"
#include "Exceptions.h"
#include <string>
#include "HelperFuncs.h"

Variable StandartFunction::run(Blackboard& blackboard) throw(ExceptionBase){
	if (value == "out") {
		for (size_t i = 0; i < params.size(); ++i)
			*(blackboard.stream) << params[i]->run(blackboard).getValue();
	}
	if (value == "in") {
		std::string val;
		std::getline(cin, val);
		double temp = atoi(val.c_str());//try to get num value
		if ((temp == 0 &&
			value[0] != '0') || !IsWordValid(val))//if can't
		{
			return Variable(val, "rValue", "string");
		}
		else
		{
			if (val.find('.') == std::string::npos)//convert number on int or double
				return Variable(val, "rValue", "int");
			else return Variable(val, "rValue", "double");
		}
	}
	return Variable("0", "rValue", "int");
}

