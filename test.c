# include<stdio.h>
int main() {
    FILE* fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("打开文件失败");
        exit(0);
    }
    for (int i = 0; i < 10000; i++) {
        fputs("Hello world", fp);
    }
    fclose(fp);
}
