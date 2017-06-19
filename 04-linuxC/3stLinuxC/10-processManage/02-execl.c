/*******************************************************************
 *   > File Name: 02-execl.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 18:12:16 2017
 ******************************************************************/
#if (0)
int execl(const char *path, const char *arg, .../* (char  *) NULL */);  //执行文件
//用来执行参数 path 字符串所代表的文件路径，接下来的参
//数代表执行该文件时传递过去的 argv〔0〕、argv[1]……，最后一个
//参数必须用空指针（NULL）作结束。
//如果执行成功则函数不会返回，执行失败则直接返回-1，失败原因
//存于 errno 中
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    execl("/bin/ls", "ls", "-al", "/etc/passwd", (char*)0);
    return 0;
}
