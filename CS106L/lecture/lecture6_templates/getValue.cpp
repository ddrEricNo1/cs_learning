#include <iostream>
#include <sstream>

template<typename T>
T getValue() {
	while (true) {
		std::cout << "Enter a " << ": ";

		std::string line; int result; char extra;
		if (!getline(std::cin, line)) {
			throw std::domain_error("Unable to get line from cin");
		}
		std::istringstream iss(line);
		if (iss >> result && !(iss >> extra)) {
			return result;
		} 
		std::cout << "Invalid format." << std::endl;
	}
}

int main() {
	auto val = getValue<int>();
	std::cout << val << std::endl;
	return 0;
}
