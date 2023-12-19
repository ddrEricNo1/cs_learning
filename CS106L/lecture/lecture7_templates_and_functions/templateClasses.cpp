/*
when making template classes, we need to #include the .cpp implementation in the .h file.
This is a compiler quirk. 
*/
#include <iostream>

template <typename T>
class Container {
public:
    Container(T val);
    T getValue();

private:
    T value;
};

template <typename T>
Container<T>::Container(T val) {
    this->value = val;
}

template<typename T>
T Container<T>::getValue() {
    return this->value;
}
int main() {

    return 0;
}