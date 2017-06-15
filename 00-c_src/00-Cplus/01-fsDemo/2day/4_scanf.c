/*******************************************************************
 *   > File Name: 4_scanf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 13:20:20 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a,ret;
    float b;
    double c;

    ret = scanf("%d%f%lf", &a,&b,&c);
    printf("ret = %d\n", ret);
    printf("a = %d,b = %d,c = %f\n", a,b,c);


    return 0;
}
