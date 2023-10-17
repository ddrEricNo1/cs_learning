#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int outcome = sum(num1, num2);
    printf("%d\n", outcome);
    return 0;
}