/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 05 Jan 2017 09:20:21 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd = 1;

    if(isatty(fd))
    {
        printf("is tty !\n");
        printf("ttyname : %s\n",ttyname(fd));
    }
    else
    {
        printf("is not tty !\n");
    }

    close(fd);

    return 0;
}
