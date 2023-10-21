#include <sstream>
#include <iostream>
using namespace std;

int main() {
	string name;
	string age;
	cout << "what is your name?";
	cin >> name;
	cout << "what is your age?";
	cin >>age;
	cout << "hello " << name << " your age is: " << age << endl;
	return 0;
}
