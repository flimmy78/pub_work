/*******************************************************************
 *   > File Name: 01-memManage.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 13:49:39 2017
 ******************************************************************/
#if (0)
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);    //配置内存空间
void *free(void *ptr);                      //释放原先配置的内存
#include <unistd.h>                 
int getpagesize(void);                      //取得内存分页大小
void *malloc(size_t size);                  //配置内存空间
#include <sys/mman.h>
//建立内存映射
void *mmap(void *addr, size_t length, int port, int flags, int fd, off_t offset);
//解除内存映射
int munmap(void *addr, size_t length);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    return 0;
}
