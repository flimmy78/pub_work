/*******************************************************************
 *   > File Name: 02-calloc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 14:06:33 2017
 ******************************************************************/
#if (0)
void *calloc(size_t nmemb, size_t size);
//配置内存空间
//calloc()配置内存时会将内存内容初始化为0
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    struct test{
        int a[10];
        char b[10];
    };


    struct test *ptr;

    ptr = calloc(sizeof(struct test), 10);
    if(ptr == NULL){
        printf("calloc error\n");exit(1);
    }
    printf("ptr--->%p\n", ptr);

    return 0;
}
