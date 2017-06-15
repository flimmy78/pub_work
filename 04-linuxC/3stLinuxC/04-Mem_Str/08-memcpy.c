/*******************************************************************
 *   > File Name: 08-memcpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 13:37:19 2017
 ******************************************************************/
#if (0)
void *memcpy(void *dest, const void *src, size_t n);
//@FUNC:拷贝内存内容，用来拷贝 src 所指的内存内容前 n 个字节到 dest 所指的
//内存地址上。与 strcpy（）不同的是，memcpy（）会完整的复制 n
//个字节，不会因为遇到字符串结束‘\0‘而结束。
//@RETURN:返回指向 dest 的指针
char *strcpy(char *dest, const char *src);
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[30] = "string[a]";
    char b[30] = "string\0string";

    int i;
    printf("strlen(a) :%d, strlen(b) :%d\n", (int)strlen(a), (int)strlen(b));
    printf("sizeof(a) :%ld, sizeof(b) :%ld\n", sizeof(a), sizeof(b));

    strcpy(a, b);

    printf("strcpy():");
    for(i = 0; i < 30; i++){
        printf("%c", a[i]);
    }

    memcpy(a, b, 30);

    printf("\nmemcpy() :");
    for(i = 0; i< 30; i++){
        printf("%c", a[i]);
    }
    puts("");
    
    return 0;
}
