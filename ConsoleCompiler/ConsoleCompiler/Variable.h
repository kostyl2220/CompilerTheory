#pragma once
#include "Element.h"
#include <string>

class Variable : public Element {
private:
	std::string varType;//type of variable
	std::string varName;//name of var
public:
	Variable(std::string const& val, std::string name, int ln = 0, int col = 0) : Element(VAR, val, ln, col), varName(name), varType("double") {};
	Variable(std::string val, std::string name, std::string tp, int ln = 0, int col = 0) : Element(VAR, val, ln, col), varName(name), varType(tp) {};
	Variable() = default;
	Variable(Variable const&) = default;
	Variable(Variable&&) = default;

	Variable& operator=(const Variable& var);
	Variable& operator=(Variable&& var);

	bool operator==(const Variable& var) const;
	bool operator!=(const Variable& var) const;

	std::string getType() const;
	std::string getName() const;
	void setValue(std::string val);
	void setType(std::string val);
	void setName(std::string name);
	Variable run(Blackboard& blackboard);
	//overriden all operators
	Variable operator+(const Variable& var);
	Variable operator-(const Variable& var);
	Variable operator>(const Variable& var);
	Variable operator<(const Variable& var);
	Variable operator/(const Variable& var);
	Variable operator*(const Variable& var);
};