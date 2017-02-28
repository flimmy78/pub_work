/*******************************************************************
 *   > File Name: 01-access.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Feb 2017 10:51:36 AM CST
 ******************************************************************/
#if (0)
int access(const char *pathname, int mode);/*判断是否具有存取文件的权限*/
//若所有欲查核的权限都通过了检查则返回 0 值，表示成功，只要有
//一权限被禁止则返回-1。
#endif

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char cmd[BUFSIZ];

    /*是否指定文件名*/
    if(argc < 2){
        printf("Usage : %s <pathname>\n",argv[0]);exit(1);
    }

    memset(cmd, 0, BUFSIZ);
    sprintf(cmd,"ls -l %s",argv[1]);
    system(cmd);

    /*文件是否存在*/
    if((access(argv[1], F_OK)) != 0){
        fprintf(stderr, "file isn't F_OK : %s\n",(char*)strerror(errno));
    }else{
        printf("file is F_OK\n");
    }

    /*文件是否可读*/
    if((access(argv[1], R_OK)) != 0){
        fprintf(stderr, "file isn't R_OK : %s\n",(char*)strerror(errno));
    }else{
        printf("file is R_OK\n");
    }

    /*文件是否可写*/
    if((access(argv[1], W_OK)) != 0){
        fprintf(stderr, "file isn't W_OK : %s\n",(char*)strerror(errno));
    }else{
        printf("file is W_OK\n");
    }

    /*文件是否可执行*/
    if((access(argv[1], X_OK)) != 0){
        fprintf(stderr, "file isn't X_OK : %s\n",(char*)strerror(errno));
    }else{
        printf("file is X_OK\n");
    }

    unlink("a.out");

    return 0;
}
