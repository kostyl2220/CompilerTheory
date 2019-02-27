// ConsoleCompiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Program.h"
#include "LexicParser.h"

std::vector<std::string> GetLines(char const* fileName)
{
	std::vector<std::string> result;
	std::ifstream infile;
	infile.open(fileName);
	std::string line;
	while (std::getline(infile, line))
	{
		result.push_back(line);
	}
	infile.close();
	return result;
}

void showMessage(std::string mes, std::string type) {
	printf("%s: %s", type.c_str(), mes.c_str());
}

int main(int argc, char* argv[])
{
	if (argc != 2 && argc != 3)
	{
		printf("Wrong parameter count!\n");
		return 1;
	}

	auto code = GetLines(argv[1]);

	char const* outputName = (argc == 3) ? argv[2] : "output.txt";
	std::ofstream out;
	out.open(outputName);

	Program pr = Program();
	try {
		pr.addCode(code);//build code
		pr.runProgram(&out);//run code
	}
	catch (CompileExeption& e) {//diiferent errors
		showMessage(e.error(), "Compile error");
	}
	catch (VariableExistsException& e) {
		showMessage(e.error(), "Variable exist");
	}
	catch (VariableNotFoundException& e) {
		showMessage(e.error(), "Variable not found");
	}
	catch (TypeException& e) {
		showMessage(e.error(), "Type mismatch");
	}
	pr.outVarList(&out);
	//PrintTokens(LexicalParse(code), &out);

	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
