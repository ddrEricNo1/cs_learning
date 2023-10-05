#include <stdio.h>

int main() {
	// 此时\t转变了原来的意思，变成了制表符
	/*
	\'表示字符常量'
	printf("%c\n",'\'');	%c用来打印字符

	\"表示字符常量“
	printf("%s\n", "\"");	%s用来打印字符串

	\\表示反斜杠
	printf("c:\\test\\test.c");
	*/
	printf("c:\test\test.c");    
	printf("\a");
	
	// \ddd表示1-3个八进制的数字
	// \xdd表示2个十六进制的数字
	printf("%c\n", '\130');
    return 0;
}
