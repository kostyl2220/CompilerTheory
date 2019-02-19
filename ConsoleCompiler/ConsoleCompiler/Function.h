#include "Variable.h"

class FunctionCall : public Element {
private:
	vector<Element*> params;
public:
	FunctionCall(string name, vector<Element*> par, int ln = 0, int col = 0) : Element(FUNC, name, ln, col), params(par) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);
};

class FunctionBody : public Element {
private:
	vector<string> params;
	Element* body;
public:
	FunctionBody(string name, vector<string> par, Element* body, int ln = 0, int col = 0) : Element(FUNC, name, ln, col), params(par), body(body) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);

	vector<string> getParameters() const;

	Element* getBody() const;
};