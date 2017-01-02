/*******************************************************************
 *   > File Name: 01-test_1.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 31 Dec 2016 06:16:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool a;
    a = !4;     //逻辑取反
    printf("a = %d\n",a);

    int b = 5,c = 3;        
    if(b < c && (c = 100))  //断路运算，表达式1为假时，将不再执行表达式2
    {
        printf("farsight\n");
    }
    printf("b = %d , c = %d\n",b,c);

    if(a > b || (a = 100))  //断路运算，表达式1为真时，将不再执行表达式2
    {
        printf("b = %d , c = %d\n",b,c);
    }
    printf("farsight\n");

    return 0;
}
