/*******************************************************************
 *   > File Name: 09-chdir.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 11:46:17 AM CST
 ******************************************************************/
#if (0)
int chdir(const char *path);/*改变当前工作目录*/
#endif

#include <stdio.h>
/*INC for chdir*/
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage : %s willchangedir\n", argv[0]);return (-1);
    }

    if(chdir(argv[1]) != 0){
        perror("chdir err");return errno;
    }

    system("ls -a");
    system("pwd");

    return 0;
}
