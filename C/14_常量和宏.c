#include <stdio.h>

// #define 定义常量宏
// define是一个预处理指令
/*
1. define定义符号
#define MAX 1000

2. define定义宏
*/
// define定义宏
// 宏进行的是替换操作，X和Y都可能是表达式，所以要用括号括起来，并且整体也需要用括号括起来
// 一个出问题的例子：如果下面的宏不用括号，4*ADD（2，3）将被替换为：4*X+Y结果输出为11
#define ADD(X, Y) ((X) + (Y))

int main() {
    printf("%d\n", 4 * ADD(2, 3));
    return 0;
}