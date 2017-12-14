/*******************************************************************
 *   > File Name: 02-read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 03 Sep 2017 09:41:03 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N   64

int main(int argc, char* argv[])
{   
    int fd, nbyte, sum = 0;
    char buf[N];

    /*1.判断命令行参数*/
    if(argc < 2){
        printf("Usage : %s  <file_name>\n", argv[0]);
        return (-1);
    }

    /*2.打开文件*/
    if((fd = open(argv[1], O_RDONLY)) < 0){
        perror("Fail to open :");
        return (-1);
    }

    /*3.循环读取文件，累加读到的字节数*/
    while((nbyte = read(fd, buf, N)) > 0){
        sum += nbyte;
    }

    printf("The length of %s is %d bytes\n", argv[0], sum);

    close(fd);

    return 0;
}
