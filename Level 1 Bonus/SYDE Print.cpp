/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 REVIEW ACTIVITY 1

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: SYDE Print
Purpose: Prints SYDE in ASCII characters
Due Date: Monday, October 5, 2020
*************************************************************
* 
Part 1:

a)Enter only one of the < or > symbols in the include directive.
	
	Errors:

	E0013 expected a file name
	E0020 identifier "cout" is undefined
	E0020 identifier "cin" is undefined
	E0020 identifier "endl" is undefined

b)Do not enter int in the int main() declaration.

	Errors:

	C4430 missing type specifier - int assumed.

c)Misspell the word main.

	Errors:

	LNK2019	unresolved external symbol _main referenced in function "int __cdecl invoke_main(void)"
	LNK1120	1 unresolved externals



d)Omit one of the brackets in the main() declaration.

	Errors:

	E0065	expected a ';'	
	E0169	expected a declaration
    E0169	expected a declaration
    LNK2019	unresolved external symbol _main referenced in function "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ)
    LNK1120	1 unresolved externals


e)Omit a semicolon from any one statement.

	Errors:

	E0065 expected a ';'


f)Misspell number_of_languages.
	
	Errors:

	E0020 identifier "number_of_languages" is undefined

g)Misspell cin or cout.
	
	Errors:

	E0020 identifier "out" is undefined

h)Omit one or both of the << symbols in the cout statement.

	Errors:

	E0065 expected a ';'

i)Omit one or both of the >> symbols in the cin statement.

	Errors:

	E0065 expected a ';'

j)Omit one of the curly brackets.

	Errors:

	E0130 expected a '{'
*/

//Part 2
#include <iostream>
using namespace std;

//Iterate row by row over all characters
//use multiple couts to better visualize it
void SYDE_Print() {
	std::cout << "*********************************************\n";
	std::cout << "     _______.____    ____  _______   _______  \n";
	std::cout << "    /       |\\   \\  /   / |       \\ |   ____|\n";
	std::cout << "   |   (----` \\   \\/   /  |  .--.  ||  |__\n";
	std::cout << "    \\   \\      \\_    _/   |  |  |  ||   __|\n";
	std::cout << ".----)   |       |  |     |  '--'  ||  |____\n";
	std::cout << "|_______/        |__|     |_______/ |_______|\n\n";
	std::cout << "*********************************************\n";
}

//redirect to SYDE print code
int main() {
	SYDE_Print();
}


