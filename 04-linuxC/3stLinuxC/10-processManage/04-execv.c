/*******************************************************************
 *   > File Name: 04-execv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jun 17 11:22:30 2017
 ******************************************************************/
#if (0)
 int execv(const char *path, char *const argv[]);//执行文件
//用来执行参数 path 字符串所代表的文件路径，与 execl（）
//不同的地方在于 execve（）只需两个参数，第二个参数利用数组指
//针来传递给执行文件。
//如果执行成功则函数不会返回，执行失败则直接返回-1，失败原因
//存于 errno 中。
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char *argv[] = {"ls", "-al", "/etc/passwd", (char*)0};
    execv("/bin/ls", argv);

    return 0;
}
