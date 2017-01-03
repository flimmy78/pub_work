/*******************************************************************
 *   > File Name: 01-scanf.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 31 Dec 2016 04:46:40 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int a, ret;
    float b;
    double c;

    printf("Please input a int , float , double :\n");
    ret = scanf("%d%f%lf",&a,&b,&c);
    printf("ret = %d\n",ret);
    printf("a = %d , b = %f , c = %f\n",a,b,c);

    return 0;
}
