/*******************************************************************
 *   > File Name: 09-getgrgid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:30:41 2017
 ******************************************************************/
#if (0)
struct group *getgrgid(git_t gid);
//用来依参数 gid 指定的组识别码逐一搜索组文件，找到
//时便将该组的数据以 group 结构返回。group 结构请参考 getgrent （）。
//返回 group 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生
#endif

#include <stdio.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    struct group *data;
    int i = 0;

    data = getgrgid(1000);
    printf("%s :%s :%d :", data -> gr_name, data -> gr_passwd, data -> gr_gid);
    while(data -> gr_name[i])
        printf("%s", data -> gr_mem[i++]);
    printf("\n");

    return 0;
}
