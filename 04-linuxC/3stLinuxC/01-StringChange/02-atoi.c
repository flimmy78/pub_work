#include <stdlib.h>
#include <stdio.h>

#if (0)
int atoi(const char *nptr);/*将字符串转换成整型数*/
#endif

int main(void)
{
    char a[]="-100";
    char b[]="456";
    int c;
    c = atoi(a)+atoi(b);
    printf("c = %d\n",c);
}
