/*******************************************************************
 *   > File Name: 04-fgetgrent.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 09:14:20 2017
 ******************************************************************/
#if (0)
struct group *fgetrent(FILE *stream);
// get group file entry
// 从参数 stream 指定的文件读取一行数据，然后以 group
// 结构将该数据返回。参数 stream 所指定的文件必须和、etc/group 相
// 同的格式。group 结构定义请参考 getgrent（）。
// 返回 group 结构数据，如果返回 NULL 则表示已无数据，或有错误
// 发生。
struct group{
    char *gr_name;      /* group name */
    char *gr_passwd;    /* group password */
    git_t gr_gid;       /* group ID */
    char **gr_mem;      /* group members */
};
#endif

#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(int argc, char* argv[])
{
    struct group *data;
    FILE *stream;
    int i;

    stream = fopen("/etc/group", "r");
    while((data = fgetgrent(stream)) != 0){
        i = 0;
        printf("%s : %s : %d :", data -> gr_name, data -> gr_passwd, data -> gr_gid);
        //Program terminated with signal SIGSEGV, Segmentation fault--->34 Line 少一个括号
        while(data -> gr_mem[i])
            printf("%s", data -> gr_mem[i++]);
        printf("\n");
    }
    fclose(stream);
    return 0;
}
