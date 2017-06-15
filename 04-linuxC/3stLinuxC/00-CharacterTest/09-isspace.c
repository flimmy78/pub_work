/*******************************************************************
 *   > File Name: 09-isspace.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:14:50 2017
 ******************************************************************/
#if (0)
int isspace(int c);
//测试字符是否为空格字符；
//判断是否为空格（‘ ’）、定位字符（‘\t’）、CR(‘\r’)、换行（‘\n’）/
//垂直定位字符（‘\v’）或者翻页（‘\f’）等情况
#endif

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char str[]="123c@#FD\tsP[e?\n";
    int i;

    for(i = 0; str[i] != 0; i++){
        if(isspace(str[i])){
            printf("str[%d] is a while-space character :%d\n", i, str[i]);
        }
    }

    return 0;
}
