/*******************************************************************
 *   > File Name: paramMacros.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 01:40:15 PM CST
 ******************************************************************/

#include <stdio.h>

#define FUN(a, b)   a+b*a

#define     FALSE   0
#define     TRUE    1

int fun(int a, int b){
    return a+b*a;
}

int main(int argc, char* argv[])
{
    int a = 5, b =3;
    int c;

    c = fun(a, b);  //函数调用
    printf("c = %d\n", c);

    c = FUN(a, b);  //宏调用

    float f;

#if (DataType == FALSE)
    f = fun(3.1, 4.5);  //Data type is error
    printf("f = %f\n", f);
#else
    f = FUN(3.1, 4.5);  //Data type is correct
    printf("f = %f\n", f);
#endif

    return 0;
}
