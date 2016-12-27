#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#if (0)
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);

#endif

int main(void)
{
    int ret1 = -1, ret2 = -1;

    if((ret1 = write(1,"Here has some data\n",19)) != 18)
        ret2 = write(2,"A write err has occurred \n ",50);

    printf("ret1 = %d\tret2 = %d\n",ret1,ret2);

    return 0;
}
