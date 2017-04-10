/*******************************************************************
 *   > File Name: 01-mkfifo.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 01:56:34 PM CST
 ******************************************************************/
#if (0)
int mkfifo(const char *pathname, mode_t mode);
//@FUNC:makes a FIFO special file with name pathname;
#endif

#include <stdio.h>
/*INC for mkfifo*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define FIFO "./MYFIFOTEST"

int main(int argc, char* argv[])
{
    char buffer[80];
    int fd;

    unlink(FIFO);
    mkfifo(FIFO, 0666);
    if(fork() > 0){
        char s[] = "hello!\n";
        fd = open(FIFO, O_WRONLY);
        write(fd, s, sizeof(s));
        close(fd);
    }else{
        fd = open(FIFO, O_RDONLY);
        read(fd, buffer, 80);
        printf("IN PPID :%s", buffer);
        close(fd);
    }

    return 0;
}
