/*******************************************************************
 *   > File Name: 01-open.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 03 Sep 2017 09:01:10 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd;

    if((fd = open("test.txt", O_RDWR|O_CREAT|O_TRUNC, 0666)) < 0){
        perror("Fail to open test.txt :");
        return (-1);
    }else{
        printf("Succeed to open test.txt, fd = %d\n ", fd);
    }

    close(fd);

    return 0;
}
