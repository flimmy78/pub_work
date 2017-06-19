/*******************************************************************
 *   > File Name: 02-dup.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 09:20:39 2017
 ******************************************************************/
#if (0)
int dup(int oldfd);//复制文件描述符
//用来复制参数 oldfd 所指的文件描述词，并将它返回。此新
//的文件描述词和参数 oldfd 指的是同一个文件，共享所有的锁定、
//读写位置和各项权限或旗标。例如，当利用 lseek（）对某个文件描
//述词作用时，另一个文件描述词的读写位置也会随着改变。
//不过，文件描述词之间并不共享 close-on-exec 旗标
//当复制成功时，则返回最小及尚未使用的文件描述词。若有错误则
//返回-1，errno 会存放错误代码
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd, copyfd;

    fd = open("./test.file", O_RDWR);
    copyfd = dup(fd);   //复制fd

    printf("%d\n", copyfd);

    //打印出fd和copyfd的偏移量，都为0
    printf("%d\n", (int)lseek(fd, 0, SEEK_CUR));
    printf("%d\n", (int)lseek(copyfd, 0, SEEK_CUR));

    lseek(fd, 3, SEEK_SET); //将fd偏移3

    //打印出fd和copyfd的偏移量，都为3
    printf("%d\n", (int)lseek(fd, 0, SEEK_CUR));
    printf("%d\n", (int)lseek(copyfd, 0, SEEK_CUR));

    return 0;
}
