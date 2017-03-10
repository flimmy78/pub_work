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

#if 1
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
    RECORD record, *mapped;
    int i, f;
    FILE *fp;

    fp = fopen("records.dat", "w+");
    for(i = 0; i<NRECORDS; i++){
        record.integer = i;
        sprintf(record.string, "RECORD-%d", i);
        fwrite(&record, sizeof(record), 1, fp);
    }
    fclose(fp);

    return 0;
}
#else
/*--------------------------------------------------------------*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*打印错误信息，并退出进程*/
#define handle_error(msg) \
    do{perror(msg);exit(EXIT_FAILURE);}while(0)

int main(int argc ,char* argv[])
{
    char *addr;/*定义字符串指针，用于接收内存映射返回的起始地址*/
    int fd;/*定义一个文件描述符的变量*/
    struct stat sb;/*文件信息数据结构体变量*/
    off_t offset, pa_offset;/*文件的起始偏移量和实际偏移量*/
    size_t length;/*偏移长度*/
    ssize_t s;/*字节长度*/

    if(argc < 3 || argc > 4){
        fprintf(stderr, "\n\t%s file offset [length]\n\n", argv[0]);exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);/*打开文件*/
    if(fd == -1){
        handle_error("open");
    }

    if(fstat(fd, &sb) == -1){/*获得文件大小，sb.st_size*/
        handle_error("fstat");
    }

    offset = atoi(argv[2]);/*获得偏移量*/
    pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) -1);/*文件映射的偏移量，必须为分页大小的整数倍*/

    if(offset >= sb.st_size){/*输入的偏移量大于文件大小*/
        fprintf(stderr, "offset is past end of file\n");exit(EXIT_FAILURE);
    }
 
    if(argc == 4){
        length = atoi(argv[3]);/*从偏移量往后的长度*/
        if(offset + length > sb.st_size){
            length = sb.st_size - offset;/*输入的偏移量最终大于文件总字节，就默认移到文件尾就行*/
        }
    }else{
        length = sb.st_size - offset;/*从偏移量到文件末尾*/
    }

    addr = mmap(NULL, length + offset - pa_offset, PROT_READ, MAP_PRIVATE, fd, pa_offset);
    if(addr == MAP_FAILED){
        handle_error("mmap");
    }

    /*从内存地址(addr + offset - pa_offset)处读取lenght个字节写到标准输出*/
    s = write(STDOUT_FILENO, addr + offset -pa_offset, length);
    if(s != length){
        if(s == -1){
            handle_error("write");
        }

        fprintf(stderr, "partial write");exit(EXIT_FAILURE);
    }

//#define TEST_DEBUG
#ifdef TEST_DEBUG
    int i;
    for(i = 0; i < length; i++){
        printf("c[%d]-(%c)  ",i,(char*)(addr + i));
    }
    puts("");
#endif
    exit(EXIT_SUCCESS);
}


#endif
