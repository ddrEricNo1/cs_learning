#include <stdio.h>

/*
union的存放顺序是所有成员从低地址开始，利用该特性可以测试CPU的大端小端方式
*/

int main() {
	union NUM {
		int a;
		char b;
	} num;
	
	num.a = 0x12345678;
	if (num.b == 0x12) 
		printf("Big Endian\n");
	else
		printf("Small Endian\n");
	printf("num.b = 0x%X\n", num.b);
	return 0;
}
