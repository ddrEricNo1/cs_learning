#include <iostream>

// input iterator is only used for withdrawing value, but in the template, we don't make restrictions on it.
// It is just a name.

template<typename InputIterator, typename DataType>
int countOccurance(InputIterator begin, InputIterator end, DataType val) {
	int count = 0;
	for (auto iter = begin; iter != end; list++) {
		if (*iter == val) ++count;
	}	
	return count;
}

int main() {
	
	return 0;
}
