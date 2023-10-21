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
