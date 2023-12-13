#include <iostream>
#include <vector>

// lambda are a type of function object, functor
template <typename InputIt, typename UnaryPred>
int countOccurence(InputIt begin, InputIt end, UnaryPred pred) {
	int count = 0;
	for (auto it = begin; it != end; it++) {
		if (pred(*it)) count++;
	}
	return count;
}

bool isLessThanLimit(int val, int limit) {
	return val < limit;
}

int main() {
	std::vector<int> vec{1, 2, 3, 4, 5, 6};
	int limit = 5;
	// limit: capture clause 
	auto lsLessThanLimit = [limit](auto val) -> bool {
		return val < limit;
	};
	int count = countOccurence(vec.begin() + vec.size() / 2, vec.end(), isLessThan5);
	std::cout << count << std::endl;
	return 0;
}
