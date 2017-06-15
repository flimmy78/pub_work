/*******************************************************************
 *   > File Name: 16-getuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 11:32:24 2017
 ******************************************************************/
#if (0)
uid_t getuid(void);//取得真实的用户识别码
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    printf("uid is %d\n", getuid());

    return 0;
}
