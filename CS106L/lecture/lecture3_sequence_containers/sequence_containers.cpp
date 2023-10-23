#include <iostream>
using namespace std;
/*
sequence containers:
	provide access to sequences of elements
	std::vector<T>
	A vector represents a sequence of elements of any type
	std::deque<T>
	A deque is a double ended queue
	can do everything a vector can do
	Unlike a vector, it is possible (and fast) to push_front and pop_front
	But for other common operations like element access, vector will always outperform a deque.
	vector is the type of sequence that should be used by default. deque is the data structure of choice when most insertions and deletions take place at the begining or at the end of the sequence.
	std::list<T>
	std::array<T>
	std::forward_list<T>
*/

void printVec(const vector<string>& v) {
	cout << "{";
	for (auto elem: v) {
		cout << elem << " ";
	}
	cout << "}" << endl;
}

int main() {
	// vector<string> names;
	// names.push_back("Anna");
	// names.push_back("Avery");
	// printVec(names);
	// cout << names.at(0) << endl;		
	
	return 0;
}
