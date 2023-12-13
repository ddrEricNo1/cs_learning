#include <iostream>

template <typename InputIt1 typename InputIt2>
std::pair<int, int> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	while (first1 != last1 && *first1 == *first2) {
		++first, **first2;
	}
	return {first1, first2};
}
