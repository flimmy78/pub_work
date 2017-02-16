#include <stdio.h>

int main(void)
{
    int a[10];

    int *p1 = &a[9],*p2 = &a[2];
    printf("p1 = %p\n",p1);
    printf("p2 = %p\n",p2);
    printf("sizeof(*p1) = %d\n",sizeof(*p1));
    printf("p1 - p2 = %d\n",p1-p2);
    printf("%d\n",((char*)p1-(char*)p2)/sizeof(*p1));
    return 0;
}
