/*******************************************************************
 *   > File Name: 42-pFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 05:33:28 PM CST
 ******************************************************************/

#include <stdio.h>

char *fun1(void){
    return "HelloWorld";
}

int main(int argc, char* argv[])
{
    char *str;
    str = fun1();

    printf("%s\n", str);

    return 0;
}
