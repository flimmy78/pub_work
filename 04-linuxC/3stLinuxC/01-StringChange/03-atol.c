#include <stdlib.h>
#include <stdio.h>

#if (0)
long atol(const char *nptr);/*将字符串转换成长整型*/
#endif

int main(void)
{
    char *a="    1000000000";
    char *b="   234567890";
    long c;

    c = atol(a) + atol(b);
    printf("a:%s\nb:%s\n",a,b);
    printf("atol(a) = %ld atol(b) = %ld c = %ld\n",atol(a),atol(b),c);
}
