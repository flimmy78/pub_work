/*******************************************************************
 *   > File Name: 15-create_fifo.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Mar 2017 01:02:47 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>

#define FIFO_MODE 0664

    /* 获得一个管道文件描述符 */
int create_fifo(const char *filename){
    static int fd, retval;

    if(filename == NULL){   /*传入的管道文件路径不能为空*/
        printf("No such file\n");return (-1);
    }

    if((retval = access(filename, F_OK)) != 0){ /*文件是否存在*/
        if((retval = mkfifo(filename, FIFO_MODE)) != 0){    /*不存在则创建*/
            fprintf(stderr, "mkfifo %s err\n",filename);return (-2);
        }
    }

    if((retval = chmod( filename, FIFO_MODE)) != 0){    /*改变文件权限*/
        fprintf(stderr, "chmod %s mode err\n",filename);return (-3);
    }

    if((fd = open(filename, O_RDWR)) < 0){  /*打开文件*/
        fprintf(stderr, "open %s err\n",filename);return (-4);
    }
    return fd;
}


#define TEST_DEBUG
#ifdef TEST_DEBUG
int main(int argc, char* argv[])
{   
    int fd;
    if(argc < 2 || argc > 2){
        printf("\n\t\tUsage :%s  <filename>\n",argv[0]);exit(EXIT_FAILURE);
    }

    printf("fd = %d\n",fd = create_fifo(argv[1]));
    
    close(fd);
    return 0;
}
#endif
