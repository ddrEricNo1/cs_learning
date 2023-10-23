/*
	When should I use a stringstream?
	1. Processing strings
		- simplify "/ ./a /b /..." to "/a"
	2. Formatting input/output 
		- uppercase, hex and other stream manipulators
	3. Parsing different types
		- stringToInteger() 
*/
#include <sstream>
#include <iostream>
using namespace std;

int getInteger(const string& prompt, const string& reprompt) {
	while(true) {
		cout << prompt << endl;
		string line;
		if (!getline(cin, line)) throw domain_error("...");
		
		isstringstream iss(line);
		int val; char remain;
		if (iss >> val && !(iss >> remain)) return val;
		cout << reprompt << endl;	
	}
}
int main() {
	
	return 0;
}
