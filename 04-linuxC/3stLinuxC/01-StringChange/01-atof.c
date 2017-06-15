/*******************************************************************
 *   > File Name: 01-atof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 11:46:53 2017
 ******************************************************************/
#if (0)
double atof(const char *nptr);
//将字符串转换成浮点型数；
#endif

#include <stdio.h>
/*INC for atof*/
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *a = "-100.23";
    char *b = "200e-2";
    float c;
    printf("a = %s,b = %s\n",a,b);

    printf("atof(a) = %f, atof(b) = %f\n", atof(a), atof(b));
    c = atof(a) + atof(b);
    printf("c = %.2f\n", c);

    return 0;
}
