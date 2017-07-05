/*******************************************************************
 *   > File Name: 01-variable.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年07月04日 星期二 21时01分23秒
 ******************************************************************/

#include <stdio.h>

//变量声明
extern int a,b;
extern int c;
extern float f;

int main(int argc, char* argv[])
{
    /*变量定义*/
    int a, b;
    int c;
    float f;

    /*初始化*/
    a = 10;
    b = 20;

    c = a + b;
    printf("value of c :%d\n", c);

    f = 70.0/3.0;
    printf("Value of f :%f\n", f);

    return 0;
}
