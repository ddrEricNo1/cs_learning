#include <stdio.h>

void test1() {
	int a = 0x80000000;
	int b  = a / -1;
	printf("%d\n", b);	// 输出结果为-2147483648

}

void test2() {
	int a = 0x80000000;
	int b = -1;
	int c = a / b;
	printf("%d\n", c);	// 运行结果为: "Floating point exception", 显然CPU检测到了异常
}

/*
为什么两者结果不同？
用objdump看test1()的反汇编代码，得知除以-1被优化成了取负指令neg，未发生除法溢出
而对于test2(), 因为a和b都是变量，无法对代码进行优化，因此直接执行除法指令

为什么显示浮点异常？
学完第七章就能解决这个问题
*/

int main() {
	test2();
	return 0;
}
