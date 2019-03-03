#include "pch.h"
#include "StandartFunction.h"
#include "Exceptions.h"
#include <string>
#include "HelperFuncs.h"
#include "Program.h"

Variable StandartFunction::run(Blackboard& blackboard) throw(ExceptionBase){
	if (value == "out") {
		for (size_t i = 0; i < params.size(); ++i)
			*(blackboard.stream) << params[i]->run(blackboard).getValue() << std::endl;
	}
	if (value == "in") {
		std::string val;
		std::getline(cin, val);
		if (val[0] == '\'')
		{
			val.erase(val.begin());
			for (size_t i = 0; i < blackboard.vars.size(); ++i)//check on variable
				if (val == blackboard.vars[i].getName()) {
					return blackboard.vars[i];
				}
			throw VariableNotFoundException("Using of undeclared variable", line, column);
		}
		
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
	if (value == "code")
	{
		std::string val;
		std::vector<std::string> code;
		std::getline(cin, val);
		while (val != "end")
		{
			code.push_back(val);
			std::getline(cin, val);
		}
		Program pr = Program();
		pr.addCode(code);
		return pr.run(blackboard);
	}
	return Variable("0", "rValue", "int");
}

