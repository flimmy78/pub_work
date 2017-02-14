/*******************************************************************
 *   > File Name: 03-strerror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 06:43:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#if (0)
#include <string.h>

char *strerror(int errnum);/*返回错误原因的描述字符串*/
//strerror（）用来依参数errnum的错误代码来查询其错误原因的描述
//字符串，然后将该字符串指针返回。
//返回描述错误原因的字符串指针。
int strerror_r(int errnum, char *buf, size_t buflen);
/* XSI-compliant */

char *strerror_r(int errnum, char *buf, size_t buflen);
/* GNU-specific */

#endif

int main(int argc, char* argv[])
{
    /*显示错误代码0--9的错误描述*/
    int i;

    for(i = 0; i< 10; i++)
    {
        printf("%d :%s\n",i,strerror(i));
    }
    return 0;
}
