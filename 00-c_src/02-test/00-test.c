#include <stdio.h>

typedef unsigned char cc_t;
typedef unsigned int  speed_t;
typedef unsigned int tcflag_t;

#define SIZE 512
#define SIZE_ (SIZE >> 1)
#define SIZE__ (SIZE >> 2)
#define SIZE___ (SIZE >> 3)

int main(void)
{
    int ret1, ret2, ret3, ret4;
    cc_t cc_c[19];
    ret4 = sizeof(cc_c);

    ret1 = sizeof(cc_t);
    ret2 = sizeof(speed_t);
    ret3 = sizeof(tcflag_t);
    
    printf("ret1 = %d, ret2 = %d, ret3 = %d\n",
            ret1, ret2, ret3);
    printf("ret4 = %d\n",ret4);

#if (0)
    int a = 10, char CH = 'o';    // error: expected identifier or ‘(’ before ‘char’
    printf("a = %d , CH = %c\n",a, CH);
#endif

    printf("SIZE : %d , SIZE_ : %d , SIZE__ : %d , SIZE___ : %d\n",SIZE,SIZE_,SIZE__,SIZE___);
    printf("BUFSIZ : %d\n",BUFSIZ);

    return 0;
}
