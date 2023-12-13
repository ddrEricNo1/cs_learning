#include <iostream>

// allow a function to accept any number of extra arguments
// when the parameter list is not empty, an optional comma may precede a ... signifying a varidric function. 

template <typename T>
void print(T value) {
	std::cout << value << std::endl;
}

template <typename T, typename... Args> 
void print(T first, Args... args) {	
	std::cout << first << " ";
	print(args...);
}

int main() {
	print(1, 2.5, "Hello", 'a');	
	return 0;
}
