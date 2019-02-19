#include "Variable.h"
#include <vector>

class StandartFunction : public Element {
private:
	vector<Element*> params;
public:
	StandartFunction(std::string const& name, vector<Element*> par, int ln = 0, int col = 0) : Element(FUNC, name, ln, col), params(par) {};

	Variable run(Blackboard& blackboard) throw(ExceptionBase);
};
