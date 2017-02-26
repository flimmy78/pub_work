/*******************************************************************
 *   > File Name: 05-errno.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Feb 2017 07:38:18 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    errno = 1;
    printf("%d:%s\n",errno,(char*)strerror(errno));

    return 0;
}
