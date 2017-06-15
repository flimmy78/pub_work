/*******************************************************************
 *   > File Name: 08-getgrent.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:13:41 2017
 ******************************************************************/
#if (0)
struct group *getgrent(void);   //从组文件中取得账号的数据
//getgrent()用来从组文件（/etc/group）中读取一项组数据，该数据以
//group 结构返回。第一次调用时会取得第一项组数据，之后每调用
//一次就会返回下一项数据，直到已无任何数据时返回 NULL。
//返回 group 结构数据，如果返回 NULL 则表示已无数据，或有错误
//发生。
//getgrent（）在第一次调用时会打开组文件，读取数据完毕后可使用
//endgrent（）来关闭该组文件。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

int main(int argc, char* argv[])
{   
    struct group *data;
    int i;

    while((data = getgrent()) != 0){
        i = 0;
        printf("%s : %s : %d :", data -> gr_name, data -> gr_passwd, data -> gr_gid);
        while(data -> gr_mem[i])
            printf("%s", data -> gr_mem[i++]);
        printf("\n");
    }
    endgrent();

    return 0;
}
