#include <stdio.h>

int main(void)
{
    int a = 100;
    int *p1 = &a;

    int **p2 = &p1;
    int ***p3 = &p2;

    printf("a = %d\n",a);
    printf("*&a = %d\n",*&a);
    printf("*p1 = %d\n",*p1);
    printf("**p2 = %d\n",**p2);
    printf("***p3 = %d\n",***p3);
    return 0;
}
