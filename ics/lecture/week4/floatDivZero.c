#include <stdio.h>

/*
为什么整数除以0会发生异常，而浮点数除以0不会出现异常
因为浮点数可以表示正负无穷：尾数部分全部为0，阶码部分全部为1
*/
void test1() {
	int a = 1; 
	int b = 0;
	printf("Division by zero: %d\n", a / b);
}

void test2() {
	double x = 1.0, y = -1.0, z = 0.0;
	printf("Division by zero: %f %f\n", x / z, y / z);
}

int main() {
	test2();
	return 0;
}
