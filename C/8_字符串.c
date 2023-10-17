#include <stdio.h>
#include <string.h>

int main() {
	// 字符串
	// char字符类型 
	// 'a' 字符常量
	// "aaa" 由双引号引起来的一串字符称为字符串字面值，或者简称字符串
	// 字符串的结束标志是\0的转义字符，在计算字符串长度时\0是结束标志，不算做字符串内容
	
	// 用字符数组存储字符串
	// 不知道大小可以不写大小，会自动根据大小动态分配
	char arr[] = "abcdef";

	// arr2中没有\0
	char arr2[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char arr3[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	printf("%s\n", arr);
	printf("%s\n", arr2);
	printf("%s\n", arr3);

	// 遇到\0停止
	int len = strlen("abc");
	int len1 = strlen(arr2);
	printf("%d\n", len);

	// 没有遇到\0
	printf("%d\n", len1);
	return 0;
}
