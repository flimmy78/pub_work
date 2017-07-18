/*******************************************************************
 *   > File Name: 06-fun_pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 14:31:38 2017
 ******************************************************************/

#include <stdio.h>

#if 0
char *fun(void) //fun为指针函数
{
    return "Hello World";
}

int main(int argc, char* argv[])
{
    char *str;

    str  = fun();
    printf("%s\n", str);

    return 0;
}
#endif

//指针函数
char *fun(void){
    return "Hello world";
}

int main(void)
{
    char *str;
    
    str = fun();
    printf("%s\n", str);
    return 0;
}
