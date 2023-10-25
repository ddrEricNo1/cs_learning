#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>


/*
map<int, int>m;
map<int, int>::iterator i = m.begin();
map<int, int>::iterator end = m.end();
while (i != end) {
	cout << (*i).first << (*i).second << std::endl;
	++i;
}
*/

const int elemToFind = 5;

void printVec(const std::vector<int>& v) {
	for (auto elem: v) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	std::cout << "Before sort" << std::endl;
	printVec(vec);
	std::sort(vec.begin(), vec.end());
	std::cout << "after sort" << std::endl;
	printVec(vec);

	std::cout << "Finding element...." << std::endl;
	// find returns an iterator which points to that element or pointing to the end of the vector
	auto it = std::find(vec.begin(), vec.end(), elemToFind);
	if (it == vec.end())	std::cout << "Not Found!!!" << std::endl;
	else std::cout << "Found element " << elemToFind << std::endl;

	std::set<int> mySet{1, 3, 57, 137};

	// return the first element which is larger than or equal to the element
	std::set<int>::iterator iter = mySet.lower_bound(2);	// returns an iterator to the first element not less than the given key
	std::set<int>::iterator end = mySet.upper_bound(57);	// return an iterator to the first element greater than the given key
	while (iter != end) {
		std::cout << *iter << std::endl;
		++iter;
	}
	return 0;
}
