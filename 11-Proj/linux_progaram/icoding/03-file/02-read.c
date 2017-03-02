/*******************************************************************
 *   > File Name: 02-read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 01 Mar 2017 05:17:51 PM CST
 ******************************************************************/
#if (0)
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE (1024*10)

int main(int argc, char* argv[])
{
    char BUF[BUFSIZE];/*缓冲buf*/
    int nread;/*读到的字节*/
    
    /*将stdin缓冲区的数据写入到BUF*/
    if((nread = read(STDIN_FILENO, BUF, BUFSIZE)) == -1){
        write(STDERR_FILENO, "A read error has occurred\n", 26 );
    }
    
    /*将BUF数据写入到stdout*/
    if((write(STDOUT_FILENO, BUF, nread)) != nread){
        write(STDERR_FILENO, "A write error has occurred\n", 27);
    }

    exit(EXIT_SUCCESS);
}
