#include <stdio.h>

int div32(int x) {
	int b = (x >> 31) & 0x1F;
	return (x + b) >>5;	
}

int main() {
	int value = 0;
	scanf("%d", &value);
	int result = div32(value);
	printf("%d\n", result);	
	return 0;
}
