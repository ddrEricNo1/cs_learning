#include <stdio.h>

/*
同样的数据，但是打印的时候结果却不同，
float 可精确表示7个10进制有效数位
*/

int main() {
	float a;
	double b;
	a = 123456.789e4;
	b = 123456.789e4;
	printf("%f\n%f\n", a, b);
	return 0;
}
