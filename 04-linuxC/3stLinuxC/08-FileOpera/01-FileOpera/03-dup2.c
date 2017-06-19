/*******************************************************************
 *   > File Name: 03-dup2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 09:44:36 2017
 ******************************************************************/
#if (0)
int dup2(int oldfd, int newfd);//复制文件描述词
//up2（）用来复制参数 oldfd 所指的文件描述词，并将它拷贝至参
//数 newfd 后一块返回。若参数 newfd 为一已打开的文件描述词，则
//newfd 所指的文件会先被关闭。dup2（）所复制的文件描述词，与
//原来的文件描述词共享各种文件状态，详情可参考 dup（）。
//当复制成功时，则返回最小及尚未使用的文件描述词。若有错误则
//返回-1，errno 会存放错误代码。
//dup2（）相当于调用 fcntl（oldfd，F_DUPFD，newfd）；请参考 fcntl
//（）。
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int fd, copyfd;

    fd = open("./test.file", O_RDWR);
    copyfd = dup2(fd, 1000);
    printf("%d, %d\n", fd, copyfd);

    //打印出fd和copyfd的偏移量，都为0
    printf("%d\n", (int)lseek(fd, 0, SEEK_CUR));
    printf("%d\n", (int)lseek(copyfd, 0, SEEK_CUR));

    //将fd的偏移量+3
    lseek(fd, 3, SEEK_SET);

    //打印出fd和copyfd的偏移量，都为3
    printf("%d\n", (int)lseek(fd, 0, SEEK_CUR));
    printf("%d\n", (int)lseek(copyfd, 0, SEEK_CUR));

    return 0;
}
