#include <iostream>
#include <vector>

class HumanGenome {
private:
    std::vector<char> data;
public:
    // move constructor
    // move is used to avoid copy and create objects for many times which may be inefficient
    HumanGenome(HumanGenome&& other) noexcept: data(std::move(other.data)) {
        std::cout << "HumanGenome move into stage" << std::endl;
    }

    // move assignment operator
    HumanGenome& operator=(HumanGenome&& other) noexcept {
        if (this != &other) {
            // other.data is l-value
            // std::move change it into x-value. It's sort of a converter between ways the compiler considers an expression's value
            data = std::move(other.data);
            std::cout << "HumanGenome moved within stage." << std::endl;
        }
        return *this;
    }
};