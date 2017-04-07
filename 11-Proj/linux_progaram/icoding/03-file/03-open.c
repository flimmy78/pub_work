/*******************************************************************
 *   > File Name: 03-open.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 09:28:12 AM CST
 ******************************************************************/
#if (0)
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);

FLAGS:
O_RDONLY
O_WRONLY
O_RDWR
O_APPEND//追加
O_TRUNC//清空
O_CREAT
O_EXCL
#endif

#include <stdio.h>
/*include file for open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
/*include file for close*/
#include <unistd.h>

#define PATHNAME    "test"
//#define FILEFLAGS   O_RDWR|O_CREAT|O_EXCL
#define FILEFLAGS   O_RDWR|O_CREAT
#define FILEMODE    0777

int main(int argc, char* argv[])
{
    int fd, retval;

    /*打开文件*/
    if((fd = open(PATHNAME,FILEFLAGS, FILEMODE)) < 0){
        perror("open file err");return errno;
    }
    
    /*关闭文件*/
    if((retval = close(fd)) < 0){
        perror("close file err");return errno;
    }


    return 0;
}
