/*******************************************************************
 *   > File Name: 07-toascii.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 05:38:13 PM CST
 ******************************************************************/

#include <stdio.h>
#include <ctype.h>

#if (0)
#include <ctype.h>
int toascii(int c);
//toascii()会将参数c 转换成7 位的unsigned char 值，第八位则会被清除，此字符即会被转成ASCII码字符
#endif

int main(int argc, char* argv[])
{
    char a = 217;
    char b;

    printf("Before toascii : a value = %d(%c)\n",a,a);
    b = toascii(a);
    printf("After toascii : a value = %d(%c)\n",b,b);

    return 0;
}
