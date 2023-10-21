#include <sstream>
#include <iostream>
using namespace std;

/*
four bits indicating the state of the stream
good bit: ready for read/write
fail bit: operation failed, all future operation frozen, e.g., type mismatch
EOF bit: previous operation reached the end of the buffer content
bad bit: external error, likely irrecoverable, e.g., the file you are reading from is deleted.
*/
int stringToInteger(const string& str) {
	// no error checking
	istringstream iss(str);
	int value;
	iss >> value;
	return value;	
}

void printState(istringstream& iss) {
	cout << "state bits: ";
	cout << (s.good() ? "G" : "-");
	cout << (s.fail() ? "F" : "-");
	cout << (s.eof() ? "E" : "-");
	cout << (s.bad() ? "B" : "-");
	cout << endl;
}

int main() {
	int result = stringToInteger("10");
	cout << result << endl;	
	return 0;
}
