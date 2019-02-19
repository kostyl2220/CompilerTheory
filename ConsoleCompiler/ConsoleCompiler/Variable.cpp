#include "pch.h"
#include "Element.h"
#include "Variable.h"
#include "Exceptions.h"
#include "string"

string Variable::getType() const{
	return varType;
}

string Variable::getName() const{
	return varName;
}

void Variable::setValue(string val) {
	value = val;
}

void Variable::setType(std::string val) {
	varType = val;
}

void Variable::setName(string name) {
	this->varName = name;
}

Variable Variable::run(Blackboard& blackboard)
{
	return *this;
}

bool Variable::operator==(const Variable& var) const
{
	return varType == var.varType
		&& varName == var.varName
		&& type == var.type
		&& value == var.value
		&& line == var.line
		&& column == var.column;
}

bool Variable::operator!=(const Variable& var) const
{
	return !(var == *this);
}

Variable& Variable::operator=(const Variable& var)
{
	if (var != *this)
	{
		varType = var.varType;
		varName = var.varName;
		type = var.type;
		value = var.value;
		line = var.line;
		column = var.column;
	}
	return *this;
}

Variable& Variable::operator=(Variable&& var)
{
	if (var != *this)
	{
		varType = std::move(var.varType);
		varName = std::move(var.varName);
		type = var.type;
		value = std::move(var.value);
		line = var.line;
		column = var.column;
	}
	return *this;
}

Variable Variable::operator+(const Variable& var) {
	if (this->getType() == "string"
		|| var.getType() == "string")
		return Variable(this->getValue() + var.getValue(), "rValue", "string");
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) + atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) + atoi(var.getValue().c_str())), "rValue", "double");
}

Variable Variable::operator-(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		throw TypeException("Can't subdivide string", line, column);//undefined
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) - atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) - atoi(var.getValue().c_str())), "rValue", "double");
}

Variable Variable::operator>(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		return Variable(to_string(this->getValue() > var.getValue()), "rValue", "string");
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) > atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) > atoi(var.getValue().c_str())), "rValue", "double");
}

Variable Variable::operator<(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		return Variable(to_string(this->getValue() < var.getValue()), "rValue", "string");
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) < atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) < atoi(var.getValue().c_str())), "rValue", "double");
}

Variable Variable::operator/(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		throw TypeException("Can't divide string", line, column);//undefined
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) / atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) / atoi(var.getValue().c_str())), "rValue", "double");
}

Variable Variable::operator*(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		throw TypeException("Can't multiply string", line, column);//undefined
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) * atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) * atoi(var.getValue().c_str())), "rValue", "double");
}

/*Variable Variable::operator==(const Variable& var){
	if (this->getType() == "string"
		|| var.getType() == "string")
		return Variable(to_string(this->getValue() == var.getValue()), "rValue", "string");
	if (this->getType() == "double"
		|| var.getType() == "double")
		return Variable(to_string(atof(this->getValue().c_str()) == atof(var.getValue().c_str())), "rValue", "double");
	return Variable(to_string(atoi(this->getValue().c_str()) == atoi(var.getValue().c_str())), "rValue", "double");
}*/