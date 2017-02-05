/*******************************************************************
 *   > File Name: 03-isascii.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 05 Feb 2017 02:48:53 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
int isascii(int c);/*测试字符是否为ASCII码字符*/
#endif

int main(int argc, char* argv[])
{
    int i,ret;

    for(i = 125; i<130; i++)
    {
        if(ret = isascii(i))
            printf("ret = %d %d is an ascii character:%c\n",ret,i,i);
        else
            printf("ret = %d %d is not an ascii character :%c\n",ret,i,i);
    }

    return 0;
}
