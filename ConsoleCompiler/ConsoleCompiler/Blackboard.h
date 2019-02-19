#pragma once
#include <iostream>
#include <vector>

class Variable;
class FunctionBody;

struct Blackboard
{
	std::vector<Variable> vars;
	std::vector<FunctionBody> funcs;
	std::ostream* stream;
};