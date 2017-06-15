/*******************************************************************
 *   > File Name: 07-getgid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:10:47 2017
 ******************************************************************/
#if (0)
gid_t getgid(void);//用来取得执行目前进程的组识别码。
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    printf("gid is %d\n", getgid());

    return 0;
}
