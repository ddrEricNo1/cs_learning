#include <stdio.h>
#include <stdint.h>

typedef uint8_t u8;
#define NREG 4
enum {RA, R1, R2, R3, R4, PC};
	

int main() {
	printf("%d\n", RA * 1);
	printf("%d\n", R1 * 1);
	printf("%d\n", R2 * 1);
	printf("%d\n", R3 * 1);
	printf("%d\n", R4 * 1);
	printf("%d\n", PC * 1);
	return 0;
}
