#include <sstream>
#include <iostream>
using namespace std;
/*
There are three reasons why  >> with cin is a nightmare:
1. cin reads the entire line into the buffer but gives you whitespace-separated tokens
2. trash in the buffer will make cin not prompt the user for input at the right time
3. when cin fails, all future cin operations fail too.
*/
int main() {
	ostringstream oss("test");
	istringstream iss(oss.str());
	int result;
	char remain;
	if ((!iss >> result) || (iss >> remain)) {
		cout << "error"<< endl;
	}
	else {
		cout << result << endl;
	}
	return 0;
}
