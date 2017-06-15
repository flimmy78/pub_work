/*******************************************************************
 *   > File Name: 08-isprint.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:10:32 2017
 ******************************************************************/
#if (0)
int isprint(int c);
//测试字符是否为可打印字符；
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "a5@;";
    int i;

    for(i = 0; str[i] != 0; i++){
        if(isprint(str[i])){
            printf("str[%d] is printable character :%d\n", i, str[i]);
        }
    }

    return 0;
}
