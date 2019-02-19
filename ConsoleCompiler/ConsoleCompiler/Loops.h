#pragma once
#include "Variable.h"

class ForLoop : public Element {
private:
	Element *start, *cond, *rep, *body;
public:
	ForLoop(Element* st, Element* cnd, Element* rp, Element* bd, int ln = 0, int col = 0) :
		Element(LOOP, "", ln, col), start(st), cond(cnd), rep(rp), body(bd) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~ForLoop() {
		delete start, cond, rep, body;
	}
};

class WhileLoop : public Element {
private:
	Element *cond, *body;
public:
	WhileLoop(Element* cnd, Element* bd, int ln = 0, int col = 0) :
		Element(LOOP, "", ln, col), cond(cnd), body(bd) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~WhileLoop() {
		delete cond, body;
	}
};

class DoWhileLoop : public Element {
private:
	Element *cond, *body;
public:
	DoWhileLoop(Element* cnd, Element* bd, int ln = 0, int col = 0) :
		Element(LOOP, "", ln, col), cond(cnd), body(bd) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	~DoWhileLoop() {
		delete cond, body;
	}
};