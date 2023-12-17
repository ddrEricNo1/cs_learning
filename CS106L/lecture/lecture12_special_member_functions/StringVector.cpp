#include "StringVector.h"
#include<iostream>

// default constructor
StringVector::StringVector(): logicalSize(0), allocatedSize(kInitialSize) {
    elems = new std::string[allocatedSize];
}

// fill constructor
StringVector:: StringVector(size_type n, const std::string& val):logicalSize(n), allocatedSize(2*n) {
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
}

// destructor
StringVector::~StringVector() {
    delete[] elems;
}

// copy constructor
// 做深拷贝，为了防止两个指针指向同一块内存
StringVector::StringVector(const StringVector& other) noexcept: logicalSize(other.logicalSize), allocatedSize(other.allocatedSize) {
    elems = new std::string[allocatedSize];
    std::copy(other.begin(), other.end(), this->begin());
}

StringVector& StringVector::operator=(const StringVector& other) {
    // 不能*this == other的原因是StirngVector并不一定需要去实现==操作，这样写可以直接比较地址
    if (this != &other) {
        // change elems to a new array of size allocatedSize
        delete[] this->elems;   // free resources
        allocatedSize = other.allocatedSize;
        logicalSize = other.logicalSize;
        elems = new std::string[allocatedSize];
        std::copy(other.begin(), other.end(), this->begin());
    }
    return *this;
}