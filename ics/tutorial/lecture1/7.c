#include <stdio.h>
void printptr(void *p) {
	printf("p = %p; *p = %0161x\n", p, *(long *)p);
}

int x;
int main(int argc, char *argv[]) {
	printptr(main);  // 代码
	printptr(&main);
	printptr(&x);	// 数据
	printptr(&argc);	// 堆栈
	printptr(argv);
	printptr(&argv);
	printptr(argv[0]);
}
