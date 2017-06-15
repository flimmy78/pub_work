/*******************************************************************
 *   > File Name: 10-getgrnam.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:38:04 2017
 ******************************************************************/
#if (0)
struct group *getgrnam(const char *name);
//etgrnam（）用来逐一搜索参数那么指定的组名称，找到时便将该
//组的数据以 group 结构返回。group 结构请参考 getgrent（）。
//返回 group 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生
#endif

#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(int argc, char* argv[])
{
    struct group *data;
    int i = 0;

    data = getgrnam("adm");
    printf("%s : %s : %d:", data -> gr_name, data -> gr_passwd, data -> gr_gid);
    while(data -> gr_mem[i])
        printf("%s", data -> gr_mem[i++]);
    printf("\n");

    return 0;
}
