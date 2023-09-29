#include <stdio.h>

int main() {
	// 1. 字面常量
	// 30，3.14，'w' 字符常量, "abc" 字符串常量
	
	// 2. const修饰的常变量
	// int a = 10;
	// a = 20; 可以成功的改变a的值，但是用const修饰之后就不能改变a的值
	const a = 10;	// 无法更改,在c语言中，const修饰的a本质是变量，但是不能被修改，有常量的属性，所以叫常变量
	int b = 10;
	int arr[a] = {0};
	// 3. 
	return 0;
}
