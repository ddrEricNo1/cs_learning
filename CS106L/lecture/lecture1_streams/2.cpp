#include <sstream>
#include <iostream>
using namespace std;

int main() {
	// we can manually move the position in the stream
	ostringstream oss("Ito En Green Tea");
	oss << 16.9;
	// fpos: a special type which represents the position, it identifies absolute positions in a stream or in a file. 
	// tellp: returns the output position indicator of the current associated streambuf object

	// streamoff() means offset
	fpos pos = oss.tellp() + streamoff(3);	
	oss.seekp(pos);
	oss << "Black";
	cout << oss.str() << endl;
	/*
	stringstream key methods:
	get position:
		oss.tellp(), iss.tellg() 
	set position:
		oss.seekp(pos), iss.seekg(pos)
	*/	
	return 0;
}
