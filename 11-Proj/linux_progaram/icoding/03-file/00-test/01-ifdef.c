/*******************************************************************
 *   > File Name: 01-ifdef.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun  7 10:42:20 2017
 ******************************************************************/

#ifdef TEST2

#include <stdio.h>

int main(int argc, char* argv[])
{

#ifdef TEST
    printf("TEST1\n");
#else
    /* 未定义，则编译 */
    printf("TEST2\n");
#endif
    return 0;
}
#endif
