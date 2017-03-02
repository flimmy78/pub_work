/*******************************************************************
 *   > File Name: 06-fseek.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 01:27:19 PM CST
 ******************************************************************/
#if (0)
/*对文件描述的读写指针进行操作*/
off_t lseek(int fd, off_t offset, int whence);
//whence : SEEK_SET/SEEK_CUR/SEEK_END
#endif

#include <stdio.h>
/*include file for lseek*/
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage: %s <file_path_name>\n",argv[0]);return (-1);
    }

    int fd,filesize;

    if((fd = open(argv[1], O_RDONLY)) < 0){
        perror("open file err");return errno;
    }

    if((filesize = lseek(fd, 0, SEEK_END)) < 0){
        perror("lseek file err");return errno;
    }else{
        printf("filesize :%d\n",filesize);
    }

    close(fd);

    return 0;
}
