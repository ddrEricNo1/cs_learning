#include <stdio.h>

// 全局变量的作用域是整个工程
int a = 10;
void test() {
	printf("test --> %d \n", a);	
}

int main() {
	/*
	变量的作用域和生命周期：	
	局部变量的生命周期：进入作用域生命周期开始，出作用域生命周期结束	
	全局变量的生命周期：整个程序的生命周期
	*/
	test();	
	return 0;
}
