#include <stdio.h>

int xy = 123;

int *fun(void)
{
    return &xy;
}

int main(void)
{
    int *p;

    p = fun();

    printf("*p = %d\n",*p);
   return 0;
}
