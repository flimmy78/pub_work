/*******************************************************************
 *   > File Name: 01-chmod.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Feb 2017 09:18:45 AM CST
 ******************************************************************/
#if (0)
#include <sys/stat.h>

int chmod(const char *path, mode_t mode);/*改变文件的权限*/
//权限改变成功返回 0，失败返回-1，错误原因存于 errno。

#endif

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FILEPATH    "./TEST/test"
#define FILEMODE    0777

int main(int argc, char* argv[])
{
    char *pathname;
    int retval;
    char CMD[BUFSIZ];

    /*获取文件路径*/
    if(argc < 2){
        pathname = FILEPATH;
        printf("Usage : %s <FILEPATH>\tDefault pathname :%s\n", argv[0], FILEPATH);
    }else{
        pathname = argv[1];
        printf("Input pathname :%s\n",pathname);
    }

    /*显示当前目录文件详细属性*/
    memset(CMD, 0, BUFSIZ);
    sprintf(CMD, "ls -l %s", pathname);
    system(CMD);

    /*改变文件权限*/
    if((retval = chmod(pathname, FILEMODE)) != 0){
        fprintf(stderr, "chmod %s err : %s\n", pathname, (char*)strerror(errno));exit(1);
    }else{
        printf("After chmod the file of %s\n",pathname);
        system(CMD);
    }

    //system("./a.out");
    unlink("./a.out");/*删掉当前目录下的可执行文件a.out*/

    return 0;
}
