/*******************************************************************
 *   > File Name: 01-write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 09:39:38 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define FILEPATHNAME    "./test.txt"
#define FILEFLAGS       O_RDWR
#define DATA    "Good morning , I am writing\n"
#define DATASIZE    sizeof(DATA)
#define DELAY_TIME  2
#define COUNTER     6

int main(int argc, char* argv[])
{
    int fd,retval;
    
    /*打开文件*/
    if((fd = open(FILEPATHNAME, FILEFLAGS)) < 0){
        perror("open err");exit(errno);
    }
    
    /*向文件写入数次数据*/
    int i = COUNTER;
    while(i--){
        if((retval = write(fd, DATA, DATASIZE)) < 0){
            perror("write err");exit(errno);
        }
        printf("write ok counter %d\n",i);
        sleep(DELAY_TIME);
    }
    
    /*关闭文件*/
    close(fd);

    return 0;
}
