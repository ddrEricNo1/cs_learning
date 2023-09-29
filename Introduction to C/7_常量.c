#include <stdio.h>

// 枚举常量
enum Color {
	RED,
	GREEN,
	BLUE
};

// 性别
enum Sex {
	MALE,
	FEMALE,
	SECRET
};

// define定义的标识符常量
#define MAX 100
int main() {
	// 1. 字面常量
	// 30，3.14，'w' 字符常量, "abc" 字符串常量
	
	// 2. const修饰的常变量
	// int a = 10;
	// a = 20; 可以成功的改变a的值，但是用const修饰之后就不能改变a的值
	const int a = 10;	// 无法更改,在c语言中，const修饰的a本质是变量，但是不能被修改，有常量的属性，所以叫常变量
	int b = 10;
	int arr[a] = {0};

	// 3. #define定义的标识符常量 
	printf("%d\n", MAX);

	// 4. 枚举常量
	// 生活中有一些值是可以一一列举出来的
	// 三原色 RED GREEN BLUE
	// 枚举类型
	// c赋值为RED
	enum Color c = RED;
	return 0;
}
