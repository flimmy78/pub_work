/*******************************************************************
 *   > File Name: 03-fput.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 29 Aug 2017 11:51:13 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int c;

    while(1){
        c = fgetc(stdin);   //从标准输入流获取一个字符
        if((c >= '0') && (c <= '9'))
            fputc(c, stdout);   //如输入的是数字，就输出
        if(c == '\n'){
            puts("");
            break;              //换行符，跳出循环
        }
    }

    return 0;
}
