#include <iostream>
#include <vector>

// count the occurences of the elements which satisfies the requirement
template <typename InputIterator, typename UniaryPredicate>
int countOccurences(InputIterator begin, InputIterator end, UniaryPredicate predicate) {
    int count = 0;
    for (auto iter = begin; iter != end; iter++) {
        if (predicate(*iter)) ++count;
    }
    return count;
}

// predicate, which takes a number of arguments and returns true or false
bool isLessThan5(int val) {
    return val < 5;
} 

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    int limit = 5;
    auto func = [limit](int val)->bool {
        return val < limit;
    };

    int count = countOccurences(vec.begin(), vec.end(), func);
    std::cout << count << std::endl;
    return 0;
}
