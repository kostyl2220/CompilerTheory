#pragma once
#include "Variable.h"

enum OpType { OP, VAL };

class Node : public Element {
private:
	Element* left;
	Element* right;
	OpType opType;
public:
	Node(std::string const& val, Element* lf, Element* rt, OpType tp, int ln = 0, int col = 0) :
		Element(NODE, val, ln, col), left(lf), right(rt), opType(tp) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~Node() {delete left, right;}
};