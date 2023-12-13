#include <stdio.h>
#define VAL 5
#define ARRLEN(array) sizeof(array)/sizeof(array[0])

int isLessthan5(int val) {
    if (val < VAL) {
        return 1;
    }
    else {
        return 0;
    }
}

int countOccurences(int *arr, int (*ptr)(int val)) {
    int count = 0;
    for (int i = 0; i < ARRLEN(arr); i++) {
        if ((*ptr)(arr[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int count = countOccurences(arr, isLessthan5);
    printf("%d\n", count);
    return 0;
}