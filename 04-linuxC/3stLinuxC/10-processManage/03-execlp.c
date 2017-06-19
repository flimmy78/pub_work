/*******************************************************************
 *   > File Name: 03-execlp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 18:22:01 2017
 ******************************************************************/
#if (0)
 int execlp(const char *file, const char *arg, .../* (char  *) NULL */);//从PATH环境变量中查找文件并执行
 //execlp（）会从 PATH 环境变量所指的目录中查找符合参数 file 的文
 //件名，找到后便执行该文件，然后将第二个以后的参数当做该文件
 //的 argv[0]、argv[1]……，最后一个参数必须用空指针（NULL）作
 //结束。
 //如果执行成功则函数不会返回，执行失败则直接返回-1，失败原因
 //存于 errno 中
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    execlp("ls", "ls", "-al", "/etc/passwd", (char*)0);
    return 0;
}
