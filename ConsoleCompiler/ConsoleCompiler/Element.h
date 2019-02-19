#pragma once
#pragma warning( disable : 4290 )

#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include "Exceptions.h"
#include "Blackboard.h"

using namespace std;

enum ElemType//types of element. used in parse
{
	ASSIGN, EXPR, COND, LOOP, PROG, VAR, NODE, LEAF, CREATE, FUNC, EMPTY, BRACK
};
class Variable;
class FunctionBody;

class Element 
{
protected:
	ElemType type;
	std::string value;
	int line, column;//for exceptions
public:
	Element() : value("") { type = EMPTY; };//constructors
	Element(std::string val, int ln = 0, int col = 0): value(val), line(ln), column(col) { type = LEAF; };
	Element(ElemType tp, std::string val, int ln = 0, int col = 0) : type(tp), line(ln), column(col), value(val) {};
	Element(Element&& el) = default;
	Element(const Element& other) = default;
	//virtual function overrided by all sons
	virtual Variable run(Blackboard& blackboard) throw(ExceptionBase);
	bool isTrue();//for condition chech on true
	std::string getValue() const;//getters & setters
	ElemType getType() const;
	void setValue(string val);
};