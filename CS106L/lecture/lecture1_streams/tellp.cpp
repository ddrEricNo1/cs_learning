#include <sstream>
#include <iostream>
using namespace std;

int main() {
	ostringstream s;
	cout << s.tellp() << endl;
	s << 'h';
	cout << s.tellp() << endl;
	s << "ello, world ";
	cout << s.tellp() << endl;
	s << 3.14 << '\n';
	cout << s.tellp() << '\n' << s.str();	
	return 0;
}
