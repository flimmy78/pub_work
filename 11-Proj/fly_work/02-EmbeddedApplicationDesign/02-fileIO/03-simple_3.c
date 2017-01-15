/*******************************************************************
 *   > File Name: 03-simple_3.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sun 15 Jan 2017 10:52:33 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE     1024        /*每次读写缓存大小，影响运行效率*/
#define SRC_FILE_NAME   "src_file"  /*源文件名*/
#define DEST_FILE_NAME  "dest_file" /*目标文件名*/
#define OFFSET          10240       /*复制的数据大小*/

int main(int argc, char* argv[])
{
    int fds,fdd;
    unsigned char buff[BUFFER_SIZE];
    int read_len;

    /*以只读方式打开文件*/
    if((fds = open(SRC_FILE_NAME, O_RDONLY)) < 0)
    {
        perror("Fail to open src_file");
        return (-1);
    }

    /*以只写方式打开目标文件，若此目标文件不存在则创建，访问权限644*/
    if((fdd = open(DEST_FILE_NAME, O_WRONLY|O_CREAT|O_TRUNC, 0644)) < 0)
    {
        perror("Fail to open dest_file");
        return (-1);
    }

    /*将源文件的读写指针移到最后10KB的起始位置*/
    lseek(fds, -OFFSET, SEEK_END);

    /*读取源文件的最后10KB数据并写到目标文件中，每次读写1KB*/
    while((read_len = read(fds, buff, sizeof(buff))) > 0)
    {
        write(fdd, buff, read_len);
    }

    close(fds);
    close(fdd);

    return 0;
}
