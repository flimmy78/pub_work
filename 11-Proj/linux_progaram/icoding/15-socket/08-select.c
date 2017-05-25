/*******************************************************************
 *   > File Name: 08-select.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 03:30:34 PM CST
 ******************************************************************/

/*INC*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char buffer[128];   /*buf*/
    int result ,nread;

    fd_set inputs, testfds; /*定义两个文件描述符集合*/
    struct timeval timeout; /*the time of timeout*/

    FD_ZERO(&inputs);       /*清空文件集合*/
    FD_SET(0, &inputs);     /*设置文件集合，将文件描述符放入集合中*/

    while(1){
        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;
    
        /*monitor multiple file descriptor*/
        result = select(1, &testfds, (fd_set *)NULL, NULL, &timeout);

        switch(result){
            case 0:                         /*timeout*/
                printf("timeout\n");
                break;
            case -1:                        /*error*/
                perror("select");
                exit(EXIT_FAILURE);
            default:                        /*检测到文件可读*/
                if(FD_ISSET(0, &testfds)){  /*确定可读的文件描述符*/

                    ioctl(0, FIONREAD, &nread);
                    if(nread == 0){
                        printf("keyboard done\n");
                        exit(EXIT_FAILURE);
                    }
                    /*统计并输出标准输入*/
                    nread = read(0, buffer, nread);
                    buffer[nread] = 0;
                    printf("read %d from keyboard :%s", nread, buffer);
                }
                break;
        }
    }

    return 0;
}
