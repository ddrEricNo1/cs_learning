#include <iostream>

template <typename T>

std::pair<T, T> my_minmax(T a, T b) {
	if (a < b) return {a, b};
	else return {b, a};
}

void printMinAndMax(int min, int max) {
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << std::endl;
}

int main() {
	auto [x, y] = my_minmax(4, 3);
	printMinAndMax(x, y);
	return 0;
}
