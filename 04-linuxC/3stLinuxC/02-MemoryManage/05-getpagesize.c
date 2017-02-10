/*******************************************************************
 *   > File Name: 05-getpagesize.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 10:40:23 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

#if (0)
#include <unistd.h>
int getpagesize(void);
//function:返回一个分页的大小，单位为字节(Byte)。
//该值为系统的分页大小，不一定会和硬件分页大小相同。
//return:内存分页的大小
#endif

int main(int argc, char* argv[])
{
    printf("pagesize = %dKB\n",getpagesize());
    return 0;
}
