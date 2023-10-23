#include<iostream>
using namespace std;
/*
a struct is a collection of named variables grouped together
*/
struct PriceRange {
	int min;
	int max;
}
struct Course {
	string code;
	// Time is another struct
	Time startTime;
	Time endTime;
	vector<string> instructors;
}

int main() {
	
	return 0;
}
