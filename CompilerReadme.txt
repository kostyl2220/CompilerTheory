Current compiler is close to C++ compiler with reduced functionality.

Types:
It supports numbers (decimal and real) and strings operations.
Numbers can be represented as decimal sequence of numbers (like 499, 949 etc.) or like real, separated with ONLY one DOT (like 5.2, 4.6). Commas are not used in real number presentation.

Variables creation:
To create variable, you should use system word "var".
Variable name can't contain any system character (described in bnf). All other chars are permited.
Variables exist only in their scope.

Loops:
All 3 typical loop types are implemented: for, do, do-while. Syntax the same as in C++.

Condition:
Common C++ if condition is implemented.

Function declaration:
To declare new function use system word "func" before function name. Also doesn't need to specify return type of func. Value of last command of function will be returned.
Don't specify type of parameters as well. Use ';' to separate parameters.
For now, function once created, exists always, despite scope.
Ex: 
func pow(x; n) 
{ 
	var res = 1;
	for (var i = 0; i < n; i = i + 1)
	{
		res = res * x;
	}
	res;
}

Function call:
Close to C++, but except of commas use ';' to separate variables;
Ex: pow(2; 5);

Standart output function:
You can use function out() with one parameter to output your value to file.
The same time you can use function in() to input something from console. To type value of real variable from code, use ' before name. '<variable_name>
Ex:
//real code
var a = 10;
var s = in();
a = 0;
out(s);
//console input
'a
//output file 
10
//Really fancy feature

Line splitting:
Compilor doesn't care about ends of line, it reads code sequentually. So you can easily type 1 lexeme on one line.
You can't split lexeme.

Features of compiler:
Every expression can be computed as value.
That is why you can easily add two blocks of code, or loops, or conditions.
The same time in IF condition part you can use expression or in FOR declaration.
Ex:
var s = 11 * for (var a = 0; a < 5; a = a + 1)
{
	l = l 
	+ a * 2;
};
THIS IS VALID IN THIS LANGUAGE.

Code func:
You can use code() function, to insert into your code, code, written from console.
Code from console can use any variable, created in real code. I know, that it's unsafe, but it's funny.
To stop typing code from console use "end" command. ("end" should be the one word in line without any additional spaces or symbols).

Example of Hello world:
out("Hello, World!");



