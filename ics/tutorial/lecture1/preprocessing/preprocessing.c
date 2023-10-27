// 本质是将stdio.h中的代码复制进来，因此可以直接替换为复制之后的代码 
// #include <stdio.h>
extern int printf(const char *__restrict __format, ...);

int main() {
	#if aa == bb
	printf("Yes\n");
#else
	printf("No\n");
#endif
}
