/*******************************************************************
 *   > File Name: 12-isxdigit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:36:48 2017
 ******************************************************************/
#if (0)
int isxdigit(int c);
//测试字符是否为16进制数字；
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "123c@#FDsP[e?";
    int i;
    printf("%s\n", str);

    for(i = 0; str[i] != 0; i++){
        if(isxdigit(str[i])){
            printf("%c is a hexadecimal digits\n", str[i]);
        }
    }


    return 0;
}
