// 只有奇数行才是true，否则为false
#define true (__LINE__ % 2 != 0)

#include <cstdio>

int main() {
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
	if (true) printf("yes %d\n", __LINE__);
}
