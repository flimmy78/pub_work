#include <stdio.h>

int *fun(int *a)
{
    *a = 100;
    return a;
}

int main(void)
{
    int x;
    int *p;

    p = fun(&x);
    printf("*p = %d\n",*p);
   return 0;
}
