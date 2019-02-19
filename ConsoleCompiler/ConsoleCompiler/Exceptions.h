#pragma once
#include <iostream>
#include <string>

class ExceptionBase : std::exception{
protected:
	std::string message;
	int line, column;
public:
	ExceptionBase(std::string const& mess, int ln, int col) : message(mess), line(ln), column(col) {};
	ExceptionBase(std::string const& mess) : message(mess) {};
	virtual const char* what() const throw()
	{
		return "Variable was not found";
	}

};

class VariableNotFoundException : public ExceptionBase{
public:
	VariableNotFoundException(std::string const& mess, int ln, int col) : ExceptionBase(mess, ln, col) {};
	VariableNotFoundException(std::string const& mess) : ExceptionBase(mess) {};
	virtual const char* what() const throw()
	{
		return "Variable was not found";
	}
	std::string error() {
		std::string err = "Variable error: ";
		err += message;
		err += " in line ";
		err += std::to_string(line);
		err += ". column ";
		err += std::to_string(column);
		return err;
	}
};

class VariableExistsException : public ExceptionBase{
public:
	VariableExistsException(std::string const& mess, int ln, int col) : ExceptionBase(mess, ln, col) {};
	VariableExistsException(std::string const& mess) : ExceptionBase(mess) {};
	virtual const char* what() const throw()
	{
		return "Variable was not found";
	}
	std::string error() {
		std::string err = "Variable error: ";
		err += message;
		err += " in line ";
		err += std::to_string(line);
		err += ". column ";
		err += std::to_string(column);
		return err;
	}
};

class TypeException : public ExceptionBase{
public:
	TypeException(std::string const& mess, int ln, int col) : ExceptionBase(mess, ln, col) {};
	TypeException(std::string const& mess) : ExceptionBase(mess) {};
	virtual const char* what() const throw()
	{
		return "Variable was not found";
	}
	std::string error() {
		std::string err = "Type error: ";
		err += message;
		err += " in line ";
		err += std::to_string(line);
		err += ". column ";
		err += std::to_string(column);
		return err;
	}
};

class CompileExeption : public ExceptionBase{
public:
	CompileExeption(std::string const& mess, int ln, int col) : ExceptionBase(mess, ln, col) {};
	virtual const char* what() const throw()
	{
		std::string err = "Compile error: ";
		err += message;
		err +=" in line ";
		err += line;
		err += ". column ";
		err += column;
		const char* temp = err.c_str();
		return temp;
	}
	std::string error() {
		std::string err = "Compile error: ";
		err += message;
		err += " in line ";
		err += std::to_string(line);
		err += ". column ";
		err += std::to_string(column);
		return err;
	}
};