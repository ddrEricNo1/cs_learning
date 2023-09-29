#include <stdio.h>

// 全部变量
// 当局部变量和全局变量相同的情况下，局部优先
int a = 1;
int main() {
	/*
	生活中有些值是不变的，例如圆周率，身份证号码
	有些值是可变的，例如年龄，体重
	*/

	/*
	变量分为局部变量和全局变量
	*/		
	
	// int age = 20;
	// float height = 88.5;
	int num1 = 0;
	int num2 = 0;
	// 输入两个整数
	scanf("%d %d", &num1, &num2);
	int sum = num1 + num2;
	printf("%d", sum);
	return 0;
}
