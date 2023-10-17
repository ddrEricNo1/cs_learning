#include <stdio.h>

int main() {
	printf("加入比特:>");
	int input = 0;
	scanf("%d", &input);
	if (input == 1) 
		printf("好offer\n");
	else
		printf("卖红薯\n");
	return 0;
}
