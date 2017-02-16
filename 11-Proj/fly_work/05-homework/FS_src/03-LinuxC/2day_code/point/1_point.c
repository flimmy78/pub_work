#include <stdio.h>

int main(void)
{
    int a = 100;
    int *pa = &a;

    printf("a = %d\n",a);
    printf("*&a = %d\n",*&a);

    printf("pa = %p\n",pa);
    printf("*&pa = %p\n",*&pa);
    printf("&*pa = %p\n",&*pa);
    return 0;
}
