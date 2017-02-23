/*******************************************************************
 *   > File Name: 02-errno.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 11:16:51 PM CST
 ******************************************************************/
#if (0)
char *strerror(int errnum);
#endif

#include <stdio.h>
#include <string.h>

#define NUM 140

int main(void)
{
    int i;

    for(i = 0; i < NUM; i++)
    {
        printf("%4d : %-50s\t",i,strerror(i));
        while( i%2 != 0)
        {
            printf("\n");
            break;
        }
    }
    puts("");

    return 0;
}
