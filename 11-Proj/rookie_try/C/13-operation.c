/*******************************************************************
 *   > File Name: 13-operation.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年06月27日 星期二 10时54分19秒
 ******************************************************************/
#if (0)
逻辑运算符：
&&
||
|
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 5;
    int b = 20;
    int c ;

    if ( a && b )
    {
        printf("Line 1 - 条件为真\n" );
    }
    if ( a || b )
    {
        printf("Line 2 - 条件为真\n" );
    }
    /* 改变 a 和 b 的值 */
    a = 0;
    b = 10;
    if ( a && b )
    {
        printf("Line 3 - 条件为真\n" );
    }
    else
    {
        printf("Line 3 - 条件不为真\n" );
    }
    if ( !(a && b) )
    {
        printf("Line 4 - 条件为真\n" );
    }


    return 0;
}
