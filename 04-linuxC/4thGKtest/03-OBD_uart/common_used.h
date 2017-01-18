#ifndef __COMMON_USED_H__
#define __COMMON_USED_H__

#include <stdio.h>

#define SUCCESS     ( 0)
#define FAILURE     (-1)

/*@file_name:commom_used.h;@func:自定义调试打印函数 */

/*---------------------Printf(string...)---------------------------------*/
#define Printf(string...)	\
do{\
	printf("%s (%d) [%s]: ",__FILE__,__LINE__,__func__);\
	printf(string);\
}while(0)

/*---------------------Printd(string...)---------------------------------*/
#define DEBUG_PRINTF (1)

#define Printd(string...)	\
        if (DEBUG_PRINTF)\
        Printf(string);

/*------------------------------------------------------------------------*/
#define BEGIN_DEBUG_PRINT(string)   \
    printf("\n");\
    Printf("------------------[ %s Beginning]------------------\n\n",(string));

#define END_DEBUG_PRINT(string)   \
    Printf("******************[ %s Ended    ]******************\n\n",(string));\
    //printf("\n");

/*------------------------------------------------------------------------*/
#define ERR_PRINT(event, string...)   \
do{\
    printf("%s (%d) [%s]: ", __FILE__, __LINE__, __func__);\
	printf("xxxxxxERRORxxxxxx  Fail to %s: ", (event));\
	printf(string);\
} while(0)

#endif

