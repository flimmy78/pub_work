/*******************************************************************
 *   > File Name: 05-memcpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 03:08:02 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#if (0)
#include <string.h>
void *memcpy(void *dest, const void *src, size_t n);
//@func:复制n个字节的数据从内存区域src到dest
//memcpy（）用来拷贝src所指的内存内容前n个字节到dest所指的
//内存地址上。与strcpy（）不同的是，memcpy（）会完整的复制n
//个字节，不会因为遇到字符串结束‘\0‘而结束。
//指针src和dest所指的内存区域不可重
//@return:返回指向dest的指针。
char *strcpy(char *dest, const char *src);
#endif

int main(int argc, char* argv[])
{   
    char a[30] = "string(a)";
    char b[30] = "STRING\0STRING";
    printf("a :%s\nb :%s\n",a,b);

    int i;
    strcpy(a,b);
    printf("strcpy():");
    for(i = 0; i<30; i++)
    {
        printf("%c",a[i]);
    }
    puts("");

    memcpy(a,b,sizeof b);
    printf("memcpy():");
    for(i = 0; i< 30; i++)
    {
        printf("%c",a[i]);
    }
    puts("");

    return 0;
}
