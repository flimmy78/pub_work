/*******************************************************************
 *   > File Name: 04-getpagesize.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 14:28:57 2017
 ******************************************************************/
#if (0)
size_t getpagesize(void);
//返回一分页的大小，单位为字节（byte）
//在Intel X86上其返回值应为4096bytes
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("Page size = %d\n", getpagesize());

    return 0;
}
