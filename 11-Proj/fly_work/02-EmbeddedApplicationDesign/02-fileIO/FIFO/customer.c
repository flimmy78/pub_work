/*******************************************************************
 *   > File Name: customer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 26 Mar 2017 08:01:43 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_FILE_SIZE   100*1024*1024   /*100MB*/
const char *fifo_file = "./myfifo"; /*仿真管道名*/
const char *tmp_fifo = "./tmp";     /*临时文件名*/

    /*消费者函数*/
int customing(const char *myfifo, int need){
    int fd;
    char buff;
    int counter = 0;

    if((fd = open(myfifo, O_RDONLY)) < 0){
        printf("Function customing error\n");return (-1);
    }

    printf("Enjoy :");
    lseek(fd, SEEK_SET, 0);
    while(counter < need){
        while((read(fd, &buff, 1) == 1) && (counter < need)){
            fputc(buff, stdout);
            counter ++;
        }
    }
    fputs("\n");
}

int main(int argc, char* argv[])
{
    return 0;
}
