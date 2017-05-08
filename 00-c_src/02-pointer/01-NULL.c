/*******************************************************************
 *   > File Name: 01-NULL.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 05:29:20 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
#if 0
    int *p = 3; //warning: initialization makes pointer from integer without a cast 
#else
    int *p = 0;
#endif
    printf("p...%p\n", p);

    return 0;
}
