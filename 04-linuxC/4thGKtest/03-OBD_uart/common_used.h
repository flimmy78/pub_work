#ifndef __COMMON_USED_H__
#define __COMMON_USED_H__

#include <stdio.h>

#define SUCCESS     ( 0)
#define FAILURE     (-1)

/*宏定义打印函数声明*/
#if (0)
Printf(string...);/*与printf（）更容易定位调试位置*/
Printd(string...);/*同Printd（）,修改定义可以关闭所有的打印调试*/
BEGIN_DEBUG_PRINT(string);/*开始执行打印调试*/
END_DEBUG_PRINT(string);/*结束执行打印调试*/
ERR_PRINT(event,string...);/*出错异常打印调试*/
/*以上均自带换行*/
#endif

/*@file_name:commom_used.h;@func:自定义调试打印函数 */

/*---------------------Printf(string...)---------------------------------*/
#define Printf(string...)	\
do{\
	printf("%s (%d) [%s]: ",__FILE__,__LINE__,__func__);\
	printf(string);\
    puts("");\
}while(0)

/*---------------------Printd(string...)---------------------------------*/
#define DEBUG_PRINTF (1)    /*为真，打印调试信息*/

#define Printd(string...)   \
        if (DEBUG_PRINTF)\
        Printf(string);

/*------------------------------------------------------------------------
 *Function name :   BEGIN_DEBUG_PRINT(string)
 *Function name :   END_DEBUG_PRINT(string)
 * ----------------------------------------------------------------------*/
#define BEGIN_DEBUG_PRINT(string)   \
    puts("");\
    Printf("------------------[ %s Beginning]------------------\n",(string));

#define END_DEBUG_PRINT(string)   \
    puts("");\
    Printf("******************[ %s Ended    ]******************\n",(string));

/*------------------------------------------------------------------------
 *Function name :   ERR_PRINT(event,string...)
 * ----------------------------------------------------------------------*/
#define ERR_PRINT(event, string...)   \
do{\
    printf("%s (%d) [%s]: ", __FILE__, __LINE__, __func__);\
	printf("xxxxxxERRORxxxxxx  Fail to %s: ", (event));\
	printf(string);\
    puts("");\
} while(0)

#endif

