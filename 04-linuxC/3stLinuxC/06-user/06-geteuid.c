/*******************************************************************
 *   > File Name: 06-geteuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:01:09 2017
 ******************************************************************/
#if (0)
uid_t geteuid(void);//取得有效的用户识别码
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    printf(" euid is %d\n", geteuid());

    return 0;
}
