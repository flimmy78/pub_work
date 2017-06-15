/*******************************************************************
 *   > File Name: 02-atoi.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 13:35:53 2017
 ******************************************************************/
#if (0)
int atoi(const char *nptr);
//convert a string to an integer
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *a = "-100.23";
    char *b = "200e-2";
    float c;

    printf("a = %s, b = %s\n", a,b);
    printf("atof(a) = %f, atof(b) = %f\n", atof(a), atof(b));
    c = atof(a) + atof(b);
    printf("c = %.2f\n", c);

    return 0;
}
