/*******************************************************************
 *   > File Name: 09-dbg.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 09:15:55 AM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
#ifdef DBG
#define dbg(str, args...)   printf("\033");
#else
#define dbg(str, args...)
#endif

#define err(str, args...)
#endif

#define dbg(str, args...)   printf("\033[1;33m %s>: FUNCTION: %s, LINE: %d, \033[0m",str, __FILE__, __func__, __LINE__, ## args);

int main(int argc, char* argv[])
{
    dbg("Hello");
    printf("\033");
    return 0;
}
