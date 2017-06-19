/*******************************************************************
 *   > File Name: 05-execve.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jun 17 16:51:27 2017
 ******************************************************************/
#if (0)
int execve(const char *filename, char *const argv[], char *const envp[]);
//执行文件
//
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char *argv[] = {"ls", "-al", "/etc/passwd", (char *)0};
    char *envp[] = {"PATH=/bin", 0};

    execve("/bin/ls", argv, envp);

    return 0;
}
