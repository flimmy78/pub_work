/*******************************************************************
 *   > File Name: 97-readGsensor.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 08 Mar 2017 03:29:04 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define GsensorFILE "/proc/gsensor"

int main(int argc, char* argv[])
{
    int retval,fd;
    char Rbuf[128];

    if((fd = open(GsensorFILE, 6)) < 0){
        perror("open Gsensor err");return (errno);
    }

    while(1){
        memset(Rbuf, 0, 128);
        if((retval = read(fd, Rbuf, 128)) < 0){
            perror("read Gsensor err");return (errno);
        }else if(retval = 0){
            printf("No data from Gsensor\n");
        }
        printf("read Data from Gsensor :%s\n",Rbuf);
        sleep(1);
    }

    return 0;
}
