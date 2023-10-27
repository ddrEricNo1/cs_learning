#include <stdio.h>

int main() {
	// 调用gcc --verbose查看gcc编译时的参数时候，有一部分显示的是#include的头文件寻找的位置
	// 而<>尖括号表示编译器将从系统路径下寻找文件，因此自己写的头文件include时不能用尖括号包裹
	
	// 但是可以解决这个问题，-I的flag允许手动将文件路径添加到编译器的搜索路径下（无空格）
	printf(
#include <a.inc>
// #include "a.inc"
);
	return 0;
}
