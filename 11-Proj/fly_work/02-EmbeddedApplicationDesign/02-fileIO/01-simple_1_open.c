/*******************************************************************
 *   > File Name: 01-simple_1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 10:19:53 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*可读写打开文件，不存在则创建，存在长度截取为0*/
#define FILE_FLAGS  O_RDWR|O_CREAT|O_TRUNC
/*打开权限*/
#define FILE_MODE   0764

int main(int argc, char* argv[])
{
    /*获取文件路径*/
    char *pathname;/*申请大小，使用才OK,此问题待深究*/
    if(argc < 2){
        printf("MoreUsage :%s filepathname\n",argv[0]);
        //pathname = (char*)malloc(sizeof "test.txt");
        pathname = "test.txt";
    }else
    {
        //pathname = (char*)malloc(sizeof argv[1]);
        pathname = argv[1];
    }
    printf("pathname :%s\n",pathname);

    /*打开文件*/
    int fd;
    fd = open(pathname, FILE_FLAGS, FILE_MODE);
    if(fd < 0){
        perror("fail to open ");return (-1);
    }

    /*关闭文件*/
    close(fd);

    return 0;
}
