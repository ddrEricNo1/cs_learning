#include <iostream>
using namespace std;

/*
	c++17 allows structured binding, allowing you to unpack the variables ina pair.
*/
pair<int, int> findPriceRange(int dist) {
	int min = static_cast<int>(dist * 0.08 + 100);
	int max = static_cast<int>(dist * 0.36 + 750);
	return make_pair(min, max);
}

int main() {
	int dist = 6542;
	auto [min, max] = findPriceRange(dist);
	cout << "you can find prices between: " << min << " and " << max << endl;	
	return 0;
}
