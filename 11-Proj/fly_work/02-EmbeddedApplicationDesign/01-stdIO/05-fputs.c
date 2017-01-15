/*******************************************************************
 *   > File Name: 05-fputs.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 10:54:40 AM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int c;
    while(1)
    {
        c = fgetc(stdin);   /*从键盘读取一个字符*/
        if((c >= '0') && (c <= '9'))
            fputc(c,stdout);    /*若输入的是数字，输出*/
        if(c == '\n')
            break;          /*遇到换行符跳出*/
    }

    return 0;
}
