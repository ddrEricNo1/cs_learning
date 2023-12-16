#include <iostream>

class Complex {
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    private:
        int data = 100;

    public:
        int real, imag;
        Complex(int r=0, int i=0) {
            real = r;
            imag = i;
        }

        Complex operator+(Complex const& obj) {
            Complex res;
            res.real = this->real + obj.real;
            res.imag = this->imag + obj.imag;
            return res;
        }
};

class Talbe {


};

std::ostream& operator<<(std::ostream& os, const Complex& obj) {
    os << obj.data << std::endl;
    return os;
}

int main() {
    Complex a1, a2, a3;
    a3 = a1 + a2;
    std::cout << a3 << std::endl;
    return 0;
}