/*******************************************************************
 *   > File Name: 08-memcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Feb 2017 04:37:41 PM CST
 ******************************************************************/
#if (0)
#include <string.h>
int memcmp(const void *s1, const void *s2, size_t n);
//比较内存s1与s2处的前n个字符；
//s1减去s2,大于0，返回1；小于0，返回-1；相等，返回0；
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

    char *a ="aBcDeF";puts(a);
    char *b ="AbCdEf";puts(b);
    char *c ="aacdef";puts(c);
    char *d ="aBcDeF";puts(d);
    printf("memcmp(a,b):%d\n",memcmp((void*)a,(void*) b,6));
    printf("memcmp(a,c):%d\n",memcmp((void*)a,(void*) c,6));
    printf("memcmp(a,d):%d\n",memcmp((void*)a,(void*) d,6));
    return 0;
}
