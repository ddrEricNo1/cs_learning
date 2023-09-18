#define true (__LINE__ % 2 != 0)

#include <stdio.h>

int main() {
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
	if (true) printf("yes %d \n", __LINE__);
}
