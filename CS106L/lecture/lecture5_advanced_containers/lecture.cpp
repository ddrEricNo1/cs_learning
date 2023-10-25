#include <iostream>
#include <string>

/*
multi-map: allows the storage of multiple same keys with differnet values
*/

/*
recap: four essential iterator operations
1, create iterator
std::set<int>::iterator iter = mySet.begin();
2. dereference iterator to read value currently pointed to
int val = *iter
3. advance iterator
iter++; or ++iter;
4. Compare against another iterator (especially ,end() iterator

*/

int main() {
	std::pair<std::string, int> p("Phone number", 153808);
	std::cout << p.first << std::endl;
	return 0;
}
