/*******************************************************************
 *   > File Name: 13-mmap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 06 Mar 2017 01:18:37 PM CST
 ******************************************************************/
#if (0)
 void *mmap(void *addr, size_t length, int prot, int flags,
                           int fd, off_t offset);
#endif

#if (0)
#include <stdio.h>
/*INC for mmap*/
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct{
    int integer;
    char string[24];
}RECORD;

#define NRECORDS    (100)

int main(int argc, char* argv[])
{
    return 0;
}
#else
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error(msg) \
    do{perror(msg);exit(EXIT_FAILURE);}while(0)

int main(int argc ,char* argv[])
{
    char *addr;
    int fd;
    struct stat sb;
    off_t offset, pa_offset;
    size_t length;
    ssize_t s;

    if(argc < 3 || argc > 4){
        fprintf(stderr, "\n\t%s file offset [length]\n\n", argv[0]);exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);/*打开文件*/
    if(fd == -1){
        handle_error("open");
    }

    if(fstat(fd, &sb) == -1){/*获得文件大小*/
        handle_error("fstat");
    }

    offset = atoi(argv[2]);/**/
    pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) -1);

    if(offset >= sb.st_size){
        fprintf(stderr, "offset is past end of file\n");exit(EXIT_FAILURE);
    }
 
    if(argc == 4){
        length = atoi(argv[3]);
        if(offset + length > sb.st_size){
            lenght = sb.st_size - offset;
        }
    }else{
        length = sb.st_size - offset;
    }

    addr = mmap(NULL, length + offset - pa_offset, MAP_PRIVATE, fd, pa_offset);
    if(addr == MAP_FAILED){
        handle_error("mmap");
    }

    s = write(STDOUT_FILENO, addr + affset -pa_ofset, length);
    if(s != length){
        if(s == -1){
            handle_error("write");
        }

        fprintf(stderr, "partial write");exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}


#endif
