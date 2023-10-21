#include <sstream>
#include <iostream>
using namespace std;

int main() {
	ostringstream oss("Ito En Green Tea");
	fpos pos = oss.tellp();
	cout << pos << endl;
	pos = oss.tellp() + streamoff(3);
	oss.seekp(pos);
	cout << pos << endl;
	ostringstream oss1("Ito En Green Tea", ostringstream::ate);
	fpos pos1 = oss1.tellp();
	cout << pos1 << endl;
	return 0;
}

