/*******************************************************************
 *   > File Name: 13-mmap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 06 Mar 2017 01:18:37 PM CST
 ******************************************************************/
#if (0)
 void *mmap(void *addr, size_t length, int prot, int flags,
                           int fd, off_t offset);
#endif

#include <stdio.h>
/*INC for mmap*/
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct{
    int integer;
    char string[24];
}RECORD;

#define NRECORDS    (100)

int main(int argc, char* argv[])
{
    return 0;
}
