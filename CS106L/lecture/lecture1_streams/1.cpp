#include <sstream>	// for string stream
#include <iostream>

/*
differences between istringstream and ostringstream:
istringstream: 用于从字符串中读取数据
ostringstream: 用于将数据输出到字符串
*/

using namespace std;

int main() {
	// output string stream
	// constructors with initial text in the buffer. can optionally provide modes such as ate(start at end) or bin(read as binary)
	ostringstream oss("Ito En Green Tea");	// construct oss with the string parameter as the initial string
	cout << oss.str() << endl;	// take whatever in the stream array and output it	

	// one thing to notice is that, the type of 16.9 is double, sringsream takes whaatever type you give to it and automatically converts that type to the string represenation of that type.
	oss << 16.9 << " Ounce ";	// when we open a stringstream, it opens it at the beginning, so it will overwrite what in the initial stream
	cout << oss.str() << endl;

	// an option is to add one attribute stringstream:ate, which means open a stream at the end
	ostringstream oss1("Ito En Green Tea", ostringstream::ate);
	oss1 << "test";
	cout << oss1.str() << endl;	// str() method takes everthing into the buffer and turns it into a string

	oss << "(Pack of " << 12 << ")";
	cout << oss.str() << endl;
	
	istringstream iss(oss.str());
	double amount;
	string unit;
	// istringstream will read to the next whitespace
	iss >> amount >> unit;
	cout << "amount: "<< amount << endl;
	cout << "unit: " << unit << endl;
	return 0;
}
