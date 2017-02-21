/*******************************************************************
 *   > File Name: 10-memset.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Feb 2017 05:17:26 PM CST
 ******************************************************************/
#if (0)
#include <string.h>

void *memset(void *s, int c, size_t n);/*将一段内存空间填入某值*/
#endif


#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char a[10];
    
    puts(((char *)memset(a, 65, 10)));

    return 0;
}
