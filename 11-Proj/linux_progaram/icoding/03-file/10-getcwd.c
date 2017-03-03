/*******************************************************************
 *   > File Name: 10-getcwd.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 12:31:27 PM CST
 ******************************************************************/
#if (0)
/*获取当前目录的路径*/
char *getcwd(char *buf, size_t size);
#endif

#include <stdio.h>
/*INC for getcwd*/
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    char BUF[128];

    if((getcwd(BUF,128)) == NULL){
        perror("getcwd err");return errno;
    }
    printf("\n%s\n",BUF);


    return 0;
}
