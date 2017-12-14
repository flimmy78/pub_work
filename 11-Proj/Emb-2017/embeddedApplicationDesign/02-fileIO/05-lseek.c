/*******************************************************************
 *   > File Name: 05-lseek.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 04 Sep 2017 11:49:08 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE         (1024*1)    /*每次读写缓存大小，影响运行效率*/
#define SRC_FILE_NAME       "src_file"  /*源文件名*/
#define DEST_FILE_NAME      "dst_file"  /*目标文件名*/
#define OFFSET              (1024*10)   /*复制的数据大小*/

int main(int argc, char* argv[])
{
    int fds, fdd;
    unsigned char buff[BUFFER_SIZE];
    int read_len;

    /*1.以只读方式打开源文件*/
    if((fds = open(SRC_FILE_NAME, O_RDONLY)) < 0){
        perror("Fail to open src_file :");
        return (-1);
    }

    /*2.以只写方式打开目标文件，若此文件不存在则创建，访问权限644*/
    if((fdd = open(DEST_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0){
        perror("Fail to open dest_file :");
        return (-1);
    }

    /*3.将源文件的读写指针移到最后10KB的起始位置*/
    lseek(fds , -OFFSET, SEEK_END);

    /*4.读取源文件的最后10KB数据并写入目标文件，每次读写1KB*/
    while((read_len = read(fds, buff, sizeof(buff))) > 0){
        write(fdd, buff, read_len);
    }

    close(fds);
    close(fdd);

    return 0;
}
