void printPtr(void *p) {
	printf("p = %p, *p = %16lx\n", p, *(long *)p);
}

int x;
int main(int argc, char*argv[]) {
	printPtr(main);	// 代码
	printPtr(&main);
	printPtr(&x);	// 数据
	printPtr(&argc);// 堆栈
	printPtr(argv);
	printPtr(&argv);
	printPtr(argv[0]);
	return 0;
}
