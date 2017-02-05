/*******************************************************************
 *   > File Name: 06-isgraph.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 03:26:28 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int isgraph(int c); /*测试字符是否为可打印字符*/
#endif

int main(int argc, char* argv[])
{
    char str[] = "@$  123";
    printf("String : %s\n",str);
    int i,ret;

    for(i = 0; str[i] != 0; i++)
    {
        if(ret = isgraph(str[i]))
            printf("ret = %d %3d is a printable character %c\n",ret,str[i],str[i]);
        else
            printf("ret = %d %3d is not a printable character\n",ret,str[i]);
    }

    return 0;
}
