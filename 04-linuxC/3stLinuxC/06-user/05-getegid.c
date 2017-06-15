/*******************************************************************
 *   > File Name: 05-getegid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 09:56:38 2017
 ******************************************************************/
#if (0)
gid_t getegid(void);//取得有效的组识别码
//用来取得执行目前进程有效组识别码。有效的组识别码
//用来决定进程执行时组的权限
#endif

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    printf("egid is %d\n", getegid());

    return 0;
}
