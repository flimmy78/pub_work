/*******************************************************************
 *   > File Name: 06-execvp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jun 17 17:01:20 2017
 ******************************************************************/
#if (0)
int execvp(const char *path, char *const argv[]);//执行文件
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char *argv[] = {"ls", "-al", "/etc/passwd", 0};

    execvp("ls", argv);


    return 0;
}
