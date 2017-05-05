/*******************************************************************
 *   > File Name: 43-pFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 05:52:47 PM CST
 ******************************************************************/

#include <stdio.h>

char *fun1(void){
    static char str[] = "hello world";
    return str;
}

int main(int argc, char* argv[])
{
    char *str;
    str = fun1();

    printf("%s\n", str);
    *str = 'H'; //.data区数据可读写
    *(str + 1) = 'E';
    *(str + 2) = 'L';
    *(str + 3) = 'L';
    *(str + 4) = 'O';
    printf("%s\n", str);


    return 0;
}
