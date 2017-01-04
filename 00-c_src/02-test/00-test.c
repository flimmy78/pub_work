#include <stdio.h>

typedef unsigned char cc_t;
typedef unsigned int  speed_t;
typedef unsigned int tcflag_t;

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
    return 0;
}
