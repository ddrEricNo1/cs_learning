#include <sstream>	// for string stream
#include <iostream>

using namespace std;

int main() {
	// output string stream
	ostringstream oss("Ito En Green Tea");	// construct oss with the string parameter as the initial string
	cout << oss.str() << endl;	// take whatever in the stream array and output it	

	oss << 16.9 << "Ounce";
	cout << oss.str() << endl;
	return 0;
}
