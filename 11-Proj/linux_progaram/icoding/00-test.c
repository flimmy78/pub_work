#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ERR
#ifdef ERR
#define PATHNAME    "~/test.txt"
#else
#define PATHNAME    "/home/fly/test.txt"
#endif
#define FFLAGS      O_RDWR

int main(void)
{
    int fd;

    if((fd = open(PATHNAME, FFLAGS)) < 0){
        perror("open file err :");
    }else{
        puts("open file success");
    }

    if((close(fd)) != 0){
        perror("close file err :");
    }else{
        puts("close file success");
    }

    return 0;
}
