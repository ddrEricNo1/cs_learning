#include <stdio.h>

int main() {
    /*
    为了有效使用内存，计算机将内存分为一个一个小的内存块，给每一个空间都编有效的地址
    32位62位机器指的是有32或者64根地址线 - 物理线 - 通电 （正电为1，负电为0）电信号 -> 数字信号
    int a = 10; a 在内存中要分配空间 -> 连续的四个字节
    拿出a的地址, &a
    */
    int a = 10;
    // * 说明pa是指针变量, int说明pa指向的对象是int类型
    int *pa = &a;
    // 取地址a拿到的是四字节中第一个字节的地址
    // %p专门用来打印地址
    printf("%p\n", &a);
    printf("%p\n", pa);

    char ch = 'w';
    char *chpc = &ch;
    printf("%p\n", chpc);
    *pa = 20;
    printf("%d\n", a);
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(float*));
    printf("%d\n", sizeof(double*));
    printf("%d\n", sizeof(unsigned int*));
    printf("%d\n", sizeof(unsigned char*));
    // 指针的大小是相同的
    // 指针用来存放地址：指针有多大取决于地址有多大
    return 0;
}