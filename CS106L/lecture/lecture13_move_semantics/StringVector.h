#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include <string>
#include <iostream>
class StringVector {
public:
    using iterator = std::string*;
    using size_type = size_t;

    size_type kInitialSize = 10;
    StringVector();
    StringVector(size_type n, const std::string& val);
    StringVector(const StringVector& other) noexcept;
    StringVector(const StringVector&& other) noexcept;
    ~StringVector();

    size_type size() const;
    bool empty() const;
    std::string& operator[] (size_type indx);
    std::string& at(size_type indx);
    const std::string& at(size_type indx) const;

    iterator insert(iterator pos, const std::string& elem);
    void push_back(const std::string& elem);
    iterator begin();
    iterator end();
    StringVector& operator+= (const StringVector& other);
    StringVector& operator+= (const std::string& rhs);
    friend StringVector operator+(const StringVector& lhs, const StringVector& rhs);
    friend StringVector operator+(const StringVector& lhs, const std::string& rhs);

    const iterator begin() const;
    const iterator end() const;

private:
    void grow();
    std::string* elems;
    size_type logicalSize;
    size_type allocatedSize;
};

#endif