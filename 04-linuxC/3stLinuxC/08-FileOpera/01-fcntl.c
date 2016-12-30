/*******************************************************************
 *   > File Name: 01-fcntl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 30 Dec 2016 04:29:50 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>

char buf[500000];

#define TEST 0
#if (TEST)
#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, ... /* arg */ );

1、获取文件的flags，即open函数的第二个参数:

flags = fcntl(fd,F_GETFL,0);

2、设置文件的flags:

fcntl(fd,F_SETFL,flags);

3、增加文件的某个flags，比如文件是阻塞的，想设置成非阻塞:

flags = fcntl(fd,F_GETFL,0);

flags |= O_NONBLOCK;

fcntl(fd,F_SETFL,flags);

4、取消文件的某个flags，比如文件是非阻塞的，想设置成为阻塞:

flags = fcntl(fd,F_GETFL,0);

flags &= ~O_NONBLOCK;

fcntl(fd,F_SETFL,flags);
#endif

int main(void)
{
    int ntowrite,nwrite;
    const char *ptr ;
    int flags;

    ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
    if(ntowrite <0) 
    {   
        perror("read STDIN_FILENO fail:");
        exit(1);
    }   
    fprintf(stderr,"read %d bytes\n",ntowrite);

    if((flags = fcntl(STDOUT_FILENO,F_GETFL,0))==-1)
    {   
        perror("fcntl F_GETFL fail:");
        exit(1);
    }   
    flags |= O_NONBLOCK;
    if(fcntl(STDOUT_FILENO,F_SETFL,flags)==-1)
    {   
        perror("fcntl F_SETFL fail:");
        exit(1);
    }   

    ptr = buf;
    while(ntowrite > 0)
    {   
        nwrite = write(STDOUT_FILENO,ptr,ntowrite);
        if(nwrite == -1) 
        {  

            perror("write file fail:");
        }   
        if(nwrite > 0)
        {   
            ptr += nwrite;
            ntowrite -= nwrite;
        }   
    }   

    flags &= ~O_NONBLOCK;
    if(fcntl(STDOUT_FILENO,F_SETFL,flags)==-1)
    {   
        perror("fcntl F_SETFL fail2:");
    }   
    return 0;
}
