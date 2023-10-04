extern int printf (const char *__restrict __format, ...);

int main() {
/*
预编译里的东西都可以先不被定义
例如
#ifdef __x86_64__
	printf("x86-64\n");
#else
	printf("x86\n");
#endif
__x86_64__是由系统定义的，但是如果一个系统不支持，则运行else部分
预编译处理的是字符串，aa==bb是空等于空
*/
#if aa == bb
	printf("Yes\n");
#else
	printf("No\n");
#endif
	return 0;
}
