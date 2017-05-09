/*******************************************************************
 *   > File Name: 07-lock1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 09:56:00 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int file_desc;
    int save_errno;

    file_desc = open("/tmp/LCK.test", O_RDWR|O_CREAT|O_EXCL, 0444);
    if(file_desc == -1){
        save_errno = errno;
        printf("Open failed with error %d\n", save_errno);
    }else{
        printf("Open succeeded\n");
    }

    unlink("/tmp/LCK.test");

    exit(EXIT_FAILURE);
}
