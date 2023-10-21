#include <sstream>
#include <iostream>
using namespace std;

int main() {
	string name;
	// getline(input, str, delim)
	/*
		input: the stream to get data from
		str: the string to put the data into
		delim: the delimiter character
	*/
	getline(cin, name, '\n'); 
	cout << name << endl;
	return 0;
}
