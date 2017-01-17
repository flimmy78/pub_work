#ifndef __COMMON_USED_H__
#define __COMMON_USED_H__

#include <stdio.h>

#define SUCCESS     (0)
#define FAILURE     (-1)

/*自定义调试打印函数*/
#define Printf(string...)   \
    do{\
        printf(" %s (%d) [%s] :",__FILE__,__LINE__,__func__);\
        printf(string);\
    }while(0)

#if (1)
#define DEBUG_PRINTF    (1)
#define Printd(string...)   \
    if(DEBUG_PRINTF)\
    Printf(string);
#endif

#endif
