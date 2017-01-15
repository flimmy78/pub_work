/*******************************************************************
 *   > File Name: 02-simple_2.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sun 15 Jan 2017 10:43:03 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 64

int main(int argc, char* argv[])
{
    int fd, nbyte, sum = 0;
    char buf[N];

    if((fd = open("test.txt",O_RDONLY)) < 0)
    {
        perror("Fail to open");
        return (-1);
    }

    while((nbyte = read(fd, buf, N)) > 0)
    {
        sum += nbyte;   //累加每次读到的字节数
    }

    printf("The length of test.txt is %d\n",sum);
    close(fd);

    return 0;
}
