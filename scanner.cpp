// Example program
// CS4303 Programming Language Concepts
// Lab exercise - Scanner
//
// Name ______________________ ID _____________________
//
// A simple lexical analyzer for C/C++-style variable declarations.
// The grammar for the declarations is as follows:
//
// <declaration> 	::= 	<type>  <var> ’;’ | <type> <var> ’=’ <number> ’;’
// <type> 		::= 	int | float
// <var> 		::= 	A | B | C | D | E
// <number> 	::= 	<integer> | <float>
// <integer> 	::= 	<integer> <digit> | <digit>
// <digit> 		::= 	0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// <float> 		::= 	<integer> ‘.’ <integer>
// 
// The task of this exercise is to write a lexical analyzer (or 
// scanner) for the tokens used in the above grammar. The following
// is the regular expression that defines the tokens:
//
//		= | ; | int | float | A | B | C | D | E | [0-9]+ | [0-9]+\.[0-9]+
//
// The program will read a declaration from the keyboard, and the
// scanner you design should recognize and print out all tokens
// included in the input. For example, given the following declaration:
//
//		int A = 123;
//
// your program should print:
//
// int
// A
// =
// 123
// ;
//
// Make sure your program print out the token one per line in the order 
// they appear in the input. Once an erroneous token is encountered, your
// scanner should print out an error message and stopped scanning. For
// example, given the following input:
//
//		int A = 0#;
//
// your program should print:
//
// int
// A
// =
// 0
// #: Error: Unrecognizable token
//
// Note that tokens may NOT be separated by spaces. For example, the above
// input:
//
//		int A = 123;
//
// does not have a space to separate 123 and ;. Also, the following inputs
// are also legal and generate the same output:
//
//		int A=123;
//		intA=123;
// 
// However, a whole token cannot be separated by spaces. For example, the
// following input will cause 12 and 3 to be regarded as two distinct tokens.
//
//		int A = 12 3;
//
// The ouput will look like:
// int
// A
// =
// 12
// 3
// ;
//
// Also note that the scanner doesn't check for syntactic errors. Therefore the
// above input is legal to this program.
//
// Other sample input:
//		float B;
//		float C=0.2;
//		short D;
//		float F;
//
// The last two sample inputs should generate errors because "short" and "F" are
// not acceptable tokens.
//
// Important!!! Save your GetToken program. We are going to use it in future 
// labs.

#include <iostream>
#include <string>

using namespace std;

string GetToken();
void error(int);

int main() {
	string token;

	cout << "Please enter a declaration in format " 
		<< "<type> <variable> [= number];" << endl;


	token = GetToken();
	cout << "The following are the tokens in the input:" << endl;

	while (token != "") {
		cout << token << endl;
		token = GetToken();
	}

	cout << "Done!" << endl;

	return 0;
}

string GetToken() {
	string token;
	char ch;
	cin.get(ch);
	if (ch == ' ') {
	    cin.get(ch);
	}
	if (ch == 'i' || ch == 'f') {
	    string buffer;
	    while(!isspace(ch)) {
	        buffer += ch;
	        cin.get(ch);
	    }
	    token += buffer;
	}
	if (isdigit(ch)) {
	    string buffer;
	    while(ch != ';') {
	        buffer += ch;
	        cin.get(ch);
	    }
	    token += buffer;
	    token += "\n;";
	}
	if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == '=') {
	    token += ch;
	}
	return token;
}