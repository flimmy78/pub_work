/*******************************************************************
 *   > File Name: 14-sysconf.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Mar 2017 04:01:23 PM CST
 ******************************************************************/
#if (0)
long sysconf(int name);
//1、前言
//
//　　当前计算机都是多核的，linux2.6提供了进程绑定cpu功能，将进程指定到某个core上执行，方便管理进程。linux提供了sysconf系统调用可以获取系统的cpu个数和可用的cpu个数。
//
//2、sysconf  函数
//
//　　man一下sysconf，解释这个函数用来获取系统执行的配置信息。例如页大小、最大页数、cpu个数、打开句柄的最大个数等等。详细说明可以参考man。
#endif

#if (0)
#include <stdio.h>
#include <unistd.h>

#define ONE_MB (1024 * 1024)

int main()
{
    printf("The number of processors configured is :%ld\n",
            sysconf(_SC_NPROCESSORS_CONF));
    printf("The number of processors currently online (available) is :%ld\n",
            sysconf(_SC_NPROCESSORS_ONLN));
    printf ("The pagesize: %ld\n", sysconf(_SC_PAGESIZE));  
    printf ("The number of pages: %ld\n", sysconf(_SC_PHYS_PAGES));  
    printf ("The number of available pages: %ld\n", sysconf(_SC_AVPHYS_PAGES)); 
    printf ("The memory size: %lld MB\n", 
            (long long)sysconf(_SC_PAGESIZE) * (long long)sysconf(_SC_PHYS_PAGES) / ONE_MB );  
    printf ("The number of files max opened:: %ld\n", sysconf(_SC_OPEN_MAX));  
    printf("The number of ticks per second: %ld\n", sysconf(_SC_CLK_TCK));  
    printf ("The max length of host name: %ld\n", sysconf(_SC_HOST_NAME_MAX));  
    printf ("The max length of login name: %ld\n", sysconf(_SC_LOGIN_NAME_MAX)); 
    return 0;
}
#else
#include <stdio.h>
#include <unistd.h>

#define ONE_MB (1024 * 1024)

int main (void)
{
    long num_procs;
    long page_size;
    long num_pages;
    long free_pages;
    long long  mem;
    long long  free_mem;
    
    printf("(_SC_PAGE_SIZE)%ld\t\t%ld K\n",sysconf(_SC_PAGE_SIZE),sysconf(_SC_PAGE_SIZE) / 1024);
    num_procs = sysconf (_SC_NPROCESSORS_CONF);
    printf ("CPU 个数为: %ld 个\n", num_procs);

    page_size = sysconf (_SC_PAGESIZE);
    printf ("系统页面的大小为: %ld K\n", page_size / 1024 );

    num_pages = sysconf (_SC_PHYS_PAGES);
    printf ("系统中物理页数个数: %ld 个\n", num_pages);

    free_pages = sysconf (_SC_AVPHYS_PAGES);
    printf ("系统中可用的页面个数为: %ld 个\n", free_pages);

    mem = (long long) ((long long)num_pages * (long long)page_size);
    mem /= ONE_MB;

    free_mem = (long long)free_pages * (long long)page_size;
    free_mem /= ONE_MB;

    printf ("总共有 %lld MB(%lld) 的物理内存, 空闲的物理内存有: %lld MB(%lld)\n", mem,\
           (long long) ((long long)num_pages * (long long)page_size),\
           free_mem,\
           (long long)free_pages * (long long)page_size);
    return (0);
}
#endif
