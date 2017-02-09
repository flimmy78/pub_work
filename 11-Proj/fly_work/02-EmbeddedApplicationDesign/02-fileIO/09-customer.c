/*******************************************************************
 *   > File Name: 09-customer.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 11:55:32 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 100*1024*1024/*100MB*/

const char *fifo_file = "./myfifo"; /*仿真FIFO文件名*/
const char *tmp_file = "./tmp";     /*临时文件名*/

/*资源消费函数*/
int customing(const char *myfifo, int need)
{
    int fd;
    char buff;
    int counter = 0;

    if((fd = open(myfifo, O_RDONLY)) < 0)
}

int main(int argc, char* argv[])
{
    return 0;
}
