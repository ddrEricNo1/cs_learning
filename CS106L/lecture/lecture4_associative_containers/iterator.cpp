#include <iostream>
#include <set>
using std::endl;
using std::cout;
using std::set;


/*
how do we iterate over an associate container?
iteraors allow iteration over any container, whether it is ordered or not

we can get an iterator pointing to the start of the sequence by calling mySet.begin()

set<int>::iterator iter = mySet.begin()

dereference: read the value

we can check if we have hit the end comparing to mySet.end()

++iter: advances the iterator

Q: why the ++ sign is put on the left side as opposed to the right side?

*/

int main() {
	set<int> container;
	for (int i = 0; i < 10; ++i) {
		container.insert(i);
	}
	set<int>::iterator itr = container.begin();
	while (itr != container.end()) {
		cout << *itr << " ";
		++itr;
	}	
	cout << endl;
	return 0;
}
