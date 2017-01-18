#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;

    fd = open("test.txt",O_RDONLY);
    if(fd < 0)
    {
        perror("[perror] open");
        printf("[printf] open test.txt err : %s\n",(char*)strerror(errno));
        fprintf(stderr,"[fprintf] open test.txt err : %s\n",(char*)strerror(errno));
        //return (-1);
    }
    
    int ret;
    ret = close(fd);
    if(ret != 0)
    {
        perror("close");
        printf("ret = %d\n",ret);
    }

    return 0;
}
