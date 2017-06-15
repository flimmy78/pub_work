/*******************************************************************
 *   > File Name: 17-strcpy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:58:40 2017
 ******************************************************************/
#if (0)
char *strcpy(char *dest, const char *src);
//@FUNC:将参数src字符串拷贝至参数dest所指向的地址
//@Return:返回参数dest的字符串起始地址；
//如果参数 dest 所指的内存空间不够大，可能会造成缓冲溢出（buffer
//Overflow）的错误情况，在编写程序时请特别留意，或者用 strncpy
//（）来取代
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[30] = "string(1)";
    char b[] = "string(2)";

    printf("Before strcpy() :%s\n", a);
    printf("After strcpy(): %s\n", strcpy(a,b));

    return 0;
}
