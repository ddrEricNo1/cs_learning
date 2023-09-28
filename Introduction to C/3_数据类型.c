#include <stdio.h>

/*
char 字符串类型
short 短整型
int 整型
long 长整型
long long 更长的整型
float 单精度浮点数
double 双精度浮点数
*/

int main() {
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(int));

	// c语言规定，sizeof(long) >= size(int)
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(long long));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));

	// C语言没有字符串类型
    return 0;
}
