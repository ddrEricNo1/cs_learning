#include <iostream>
using namespace std;

int main() {
	float heads;
	cout.setf(ios::fixed, ios::floatfield);
	while (1) {
		cout << "Please enter a number: ";
		cin >> heads;
		cout << heads << endl;
	}
	return 0;
}
