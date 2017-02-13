/*******************************************************************
 *   > File Name: 02-bcopy.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 08:15:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#if (0)
#include <strings.h>

void bcopy(const void *src, void *dest, size_t n);
//bcopy()与 memcpy（）一样都是用来拷贝 src 所指的内存内容前 n
//个字节到 dest 所指的地址，不过参数 src 与 dest 在传给函数时是相
//反的位置
void *memcpy(void *dest, const void *src, size_t n);

#endif

int main(int argc, char* argv[])
{
    char dest[30] = "string(a)";
    char src[30] = "string\0STRING";
    printf("dest :%s\nsrc :%s\n",dest,src);

    int i;

    bcopy(src, dest, 30);/*src指针放在前*/
    printf("bcopy():");
    for(i = 0;i < 30; i++)
        printf("%c",dest[i]);
    memcpy(dest, src, 30);/*dest指针放在前*/
    printf("\nmemcpy():");
    for(i = 0;i < 30; i++)
        printf("%c",dest[i]);
    puts("");

    return 0;
}
