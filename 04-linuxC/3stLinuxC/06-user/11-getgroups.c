/*******************************************************************
 *   > File Name: 11-getgroups.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:46:32 2017
 ******************************************************************/
#if (0)
int getgroups(int size, gid_t list[]);
//用来取得目前用户所属的组代码。参数 size 为 list〔〕
//所能容纳的 gid_t 数目。如果参数 size 值为零，此函数仅会返回用
//户所属的组数。
//返回组识别码，如有错误则返回-1
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    gid_t list[500];
    int x,i;

    x = getgroups(0, list);
    getgroups(x, list);
    
    for(i = 0; i< x; i++)
        printf("%d : %d\n", i, list[i]);

    return 0;
}
