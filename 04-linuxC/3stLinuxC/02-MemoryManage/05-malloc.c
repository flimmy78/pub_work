/*******************************************************************
 *   > File Name: 05-malloc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 14:34:20 2017
 ******************************************************************/
#if (0)
void *malloc(size_t size);
//配置内存空间
//成功返回指针，失败返回NULL;
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    void *p = malloc(1024);
    printf("p--->%p\n",p);
    free(p);

    return 0;
}
