#include <stdio.h>

struct Stu {
    char name[20];
    int age;
    double score;
};

struct Book {
    char name[20];
    float price;
    char id[30];
};

int main() {
    // 结构体可以描述复杂对象
    // 结构体可以让c语言创建一些类型
    struct Stu s = {"张三", 20, 85.5};  //结构体的创建和初始化
    printf("%s %d %lf\n", s.name, s.age, s.score);
    struct Stu *ptr_s = &s;
    printf("%s %d %lf\n", (*ptr_s).name, (*ptr_s).age, (*ptr_s).score);
    printf("%s %d %lf\n", ptr_s->name, ptr_s->age, ptr_s->score);


    return 0;
}