#include <stdio.h>

int main() {
    // 数组：一组相同类型的元素集合
    // 不完全初始化，默认其余为0
    // 数组用下标访问
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", arr[4]);
    return 0;
}