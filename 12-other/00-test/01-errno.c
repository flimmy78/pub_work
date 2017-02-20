/*******************************************************************
 *   > File Name: 01-errno.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 20 Feb 2017 11:22:43 AM CST
 ******************************************************************/
#if (0)
#include <string.h>
char *strerror(int errnum);
#endif


#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int no = 0;

    errno = no;
    printf("%d:%s\n",errno,strerror(errno));

    return 0;
}
