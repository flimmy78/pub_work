/*******************************************************************
 *   > File Name: 08-lock1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 25 Apr 2017 09:34:06 AM CST
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
        save_errno = file_desc;
        printf("Open filed with error %d\n", save_errno);
    }else{
        printf("Open succeed\n");
    }

    return 0;
}
