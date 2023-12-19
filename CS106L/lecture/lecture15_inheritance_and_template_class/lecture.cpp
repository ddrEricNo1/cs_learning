#include <iostream>
#include <string>
using std::cout; using std::endl;

/*
Always call the superclass constructor.
If not specified, call the default constructor of base. 

If intend to make the class inheritable, (i.e. if your class has any virtual functions), make the destructor virtual.
Otherwise will almost definitely have memory leaks. 
*/

class Drink {
public:
    // 使用默认的构造函数
    Drink() = default;
    Drink(std::string flavor) : _flavor(flavor) {}
    // virtual void make() = 0;
    virtual void make() {
        cout << "Make Drink from Drink class" << endl;
    }

    // make the destructor virtual is that we want to guarantee that if you declare an object of type derived but 
    // declare a pointer to the object base, the virtual ensures that if delete to B, it will go the derived destructor
    virtual ~Drink() = default;

private:
    std::string _flavor;
};

class Tea: public Drink {
public:
    Tea() = default;
    Tea(std::string flavor): Drink(flavor) {}
    ~Tea() = default;

    void make() {
        cout << "Made tea from the Tea class" << endl;
    }
};

int main() {
    Tea tea("red");    
    tea.Drink::make();
    return 0;
}