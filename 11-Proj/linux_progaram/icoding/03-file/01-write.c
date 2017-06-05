/*******************************************************************
 *   > File Name: 01-write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 05 Jun 2017 04:36:45 PM CST
 ******************************************************************/
#if (0)
size_t write(int fildes, const void *buf, size_t nbyte);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DATA1   "Here is some data\n"
#define DATA2   "A write error has occured on file descriptor one\n"
#define DATA1_LEN   sizeof(DATA1)
#define DATA2_LEN   sizeof(DATA2)

int main(void)
{
    printf("%d,%d\n", DATA1_LEN, DATA2_LEN);
    if(write(1, DATA1, DATA1_LEN) != 18){
        write(2, DATA2, DATA2_LEN);
    }

    return 0;
}
