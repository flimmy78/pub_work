/*******************************************************************
 *   > File Name: 04-simple_3_copy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 03:33:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024

int copy_file(const char *src_file, const char *dst_file)
{
    int fds,fdd;
    unsigned char buf[BUF_SIZE];
    int read_len;
    struct timeval start_time, end_time;

    /*开始运行*/
    if((gettimeofday(&start_time, NULL)) != 0){
        perror("gettimeofday start_time err");
    }

    /*以只读的方式打开源文件*/
    if((fds = open(src_file, O_RDONLY)) < 0){
        perror("fail to open src_file");return (-1);
    }
    
    /*以可读写的方式打开目标文件，不存在则创建，存在长度截为0*/
    if((fdd = open(dst_file, O_RDWR|O_CREAT|O_TRUNC, 0664)) < 0){
        perror("fail to open dst_file");return (-1);
    }

    /*读取源文件，写入到目标文件中*/
    while((read_len = read(fds, buf, sizeof(buf))) > 0){
        write(fdd, buf, read_len);
    }

    /*关闭文件*/
    close(fds),close(fdd);
    
    /*结束运行*/
    if((gettimeofday(&end_time, NULL)) != 0){
        perror("gettimeofday end_time err");
    }

    printf("RUN_TIME: %lds:%ldms\n",\
            (end_time.tv_sec - start_time.tv_sec),\
            (end_time.tv_usec - start_time.tv_usec));

    return 0;
}

int main(int argc, char* argv[])
{
    if(argc < 3){
        printf("Usage :%s src_file dst_file\n",argv[0]);return 0;
    }

    copy_file(argv[1],argv[2]);

    return 0;
}
