/*******************************************************************
 *   > File Name: 07-mmap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 10:56:04 AM CST
 ******************************************************************/

#include <stdio.h>

#if (0)
#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr,size_t length);
//@function:mmap()用来将某个文件内容映射到内存中，对该内存区域的存取即
//是直接对该文件内容的读写。
//@return:映射成功则返回映射区的起始地址，反之返回MAP_FAILED（-1）及错误码
//@param(addr):欲映射的地址，设为NULL，系统自动选择
//@param（length）:将文件多大部分映射到内存
//@param（prot）:映射区域的保护方式，组合如下
//PROT_EXEC  Pages may be executed.
//
//PROT_READ  Pages may be read.
//
//PROT_WRITE Pages may be written.
//
//PROT_NONE  Pages may not be accessed.
//@param(flags):参数 flags 会影响映射区域的各种特性
//@param(fd):欲映射的文件
//@param(offset):为文件映射的偏移量，通常设置为 0，代表从文件最前方
//开始对应，offset 必须是分页大小的整数倍。
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    /*利用mmap()来读取/etc/passwd文件内容*/
    int fd;
    void *start;
    struct stat sb;

    fd = open("/etc/passwd",O_RDONLY);/*打开文件*/
    fstat(fd, &sb);/*获取文件状态*/
    start = mmap(NULL, sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);/*建立内存映射*/
    if(start == MAP_FAILED) /*判断映射是否成功*/
        return (-1);
    printf("%s",(char*)start);
    munmap(start, sb.st_size);/*解除映射*/
    close(fd);

    return 0;
}
