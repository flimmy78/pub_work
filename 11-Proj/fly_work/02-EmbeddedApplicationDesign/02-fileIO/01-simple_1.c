/*******************************************************************
 *   > File Name: 01-simple.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 11:07:59 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd;
    
    if((fd = open("test.txt",O_RDWR|O_CREAT|O_TRUNC, 0666)) <0)
    {
        perror("Fail to open");
        return (-1);
    }
    close(fd);

    return 0;
}
