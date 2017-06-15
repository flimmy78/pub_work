/*******************************************************************
 *   > File Name: 06-isgraphis.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 10:18:30 2017
 ******************************************************************/
#if (0)
int isgraph(int c);
//测试字符是否为可打印字符；
//
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "a5@;";
    int i;

    for(i = 0; str[i] != 0; i++){
        if(isgraph(str[i])){
            printf("str[%d] is printable character :%d -- %c\n", i, str[i], str[i]);
        }
    }

    return 0;
}
