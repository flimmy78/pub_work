/*******************************************************************
 *   > File Name: 01-write.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 01 Mar 2017 04:52:DATA2_LEN PM CST
 ******************************************************************/
#if (0)
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
#endif

#include <stdio.h>
#include <unistd.h>

#define DATA1 "WriteSomeDataToSTDOUT\n"
#define DATA2 "WriteDataERR\n"
#define DATA1_LEN   sizeof(DATA1)
#define DATA2_LEN   sizeof(DATA2)


int main(int argc, char* argv[])
{
    int retval;

    printf("sizeof DATA1:%d  sizeof DATA2:%d\n",DATA1_LEN,DATA2_LEN);
    if((retval = write(1,DATA1,DATA1_LEN)) != 17){
        write(2,DATA2,DATA2_LEN);
    }

    return 0;
}
