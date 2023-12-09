#include <iostream>
#include <string>
#include <sstream>

int main() {
	std::istringstream iss("16.9 \n Ounces.	. 	\t	-38271");
	int token1;
	std::string token2;
	char token3;
	bool token4;
	iss >> token1 >> token2 >> token3 >> token4;
	std::cout << token1 << " " << token2 << " " << token3 << " " << token4 << " " << std::endl;
	return 0;
}
