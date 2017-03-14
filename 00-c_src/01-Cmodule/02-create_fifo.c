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

int create_fifo(const char *filename){
    static int fd, retval;

    if(filename == NULL){
        printf("No such file\n");return (-1);
    }

    if((retval = access(filename, F_OK)) != 0){
        if((retval = mkfifo(filename, 0777)) != 0){
            fprintf(stderr, "mkfifo %s err\n",filename);return (-2);
        }
    }

    if((retval = chmod( filename, 0777)) != 0){
        fprintf(stderr, "chmod %s mode err\n",filename);return (-3);
    }

    if((fd = open(filename, O_RDWR)) < 0){
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
