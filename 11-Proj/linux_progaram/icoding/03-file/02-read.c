/*******************************************************************
 *   > File Name: 02-read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 05 Jun 2017 05:08:33 PM CST
 ******************************************************************/
#if (0)
size_t read(int fildes, void *buf, size_t nbytes);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char buffer[128];
    int nread;

    nread = read(1 , buffer, 128);
    if(nread == -1)
        write(2, "A read error has occurred\n", 26);

    if((write(1, buffer, nread)) != nread)
        write(2, "A write error has occured\n", 27);

    return 0;
}
