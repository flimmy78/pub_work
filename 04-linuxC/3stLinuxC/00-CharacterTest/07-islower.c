/*******************************************************************
 *   > File Name: 07-islower.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 10:49:26 2017
 ******************************************************************/
#if (0)
int islower(int c);
//测试字符是否为小写字母
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[] = "123@#FDsP[e?";
    int i;

    printf("%s\n", str);
    for(i = 0; str[i] != 0; i++){
        if(islower(str[i])){
            printf("%c is a lower-case character\n", str[i]);
        }
    }

    return 0;
}
