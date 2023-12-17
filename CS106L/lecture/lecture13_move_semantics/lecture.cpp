#include <iostream>
#include <string>
#include <vector>

/*
emplace_back和push_back区别
emplace_back和push_back都是用于在容器尾部添加元素
push_back将已经存在的对象添加到容器尾部，需要创建该对象
emplace_back在容器尾部直接添加一个新对象，而不需要先创建一个对象再将其复制或移动到容器中，允许在容器内部直接构造元素，避免
不必要的复制或移动操作，性能上更加高效，尤其在处理大型对象或者有显著构造成本的对象时更为明显
*/

class President {
public:
    std::string name;
    std::string born;
    int born_year;
    President(std::string name, std::string born, int born_year) {
        this->name = name;
        this->born = born;
        this->born_year = born_year;
    }
};

/*
l-value: an expression that has a name (identity), can find address using address-of opeartor(&var)
r-value: an expression that does not have a name (identity). temporary values, cannot find address using address-of operator
*/

/*
copy constructor: create new from existing l-value
copy assignment: overwrite existing from existing l-value
move constructor: create new from existing r-value
move asisgnment: overwrite existng from existing r-value
*/

int main() {
    std::vector<President> elections;
    std::cout << "emplace back\n" << std::endl;
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    std::vector<President> reElections;
    std::cout << "\npush_back\n" << std::endl;
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));
    return 0;
}