/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 04 Jan 2017 04:43:57 PM CST
 ******************************************************************/

#include <stdio.h>

#define CSIZE 0000060

int main(void)
{

    printf("%d\n",CSIZE);
    printf("%c\n",CSIZE);
    printf("%d\n",~CSIZE);
    //printf("%s\n",CSIZE);//
    //warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
    printf("[%d-%d]\n",0xEE,0xBB);
    printf("[%c-%c]\n",0xEE,0xBB);

    return 0;
}
