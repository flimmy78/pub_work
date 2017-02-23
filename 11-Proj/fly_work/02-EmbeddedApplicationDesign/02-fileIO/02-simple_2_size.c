/*******************************************************************
 *   > File Name: 02-simple_2_size.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 02:52:10 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 64/*BUF大小*/

/*计算文件的大小，字节byte*/
int filesize(const char *pathname)
{
    int fd, nbyte, sum = 0;
    char buf[N];

    /*打开文件*/
    if((fd = open(pathname,O_RDONLY)) < 0){
        perror("fail to open");return (-1);
    }
    
    /*读取文件，将读到的字节数累加*/
    while((nbyte = read(fd, buf, N)) > 0){
        sum += nbyte;
    }
    
    close(fd);/*关闭文件*/
    return sum;/*返回文件大小*/
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage : %s filepathname\n",argv[0]);return (-1);
    }

    int file_size;
    file_size = filesize(argv[1]);
    printf("file_size :%d\n",file_size);

    return 0;
}
