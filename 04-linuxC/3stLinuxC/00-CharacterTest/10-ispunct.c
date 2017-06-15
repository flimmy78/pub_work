/*******************************************************************
 *   > File Name: 10-ispunct.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:26:03 2017
 ******************************************************************/
#if (0)
int ispunct(int c);
//测试字符是否为标点符号或特殊符号
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "123c@#FDsP[e?";
    int i;

    for(i = 0; str[i] != 0; i++){
        if(ispunct(str[i])){
            printf("%c\n", str[i]);
        }
    }

    return 0;
}
