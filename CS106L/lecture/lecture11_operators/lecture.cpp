#include <iostream>

StringVector operator+(const StringVector& first, const StringVector& second) {
    StringVector result = first;
    for (const std::string s: second) {
        result += s;
    }
    return result;
}

int main() {
    return 0;
}
