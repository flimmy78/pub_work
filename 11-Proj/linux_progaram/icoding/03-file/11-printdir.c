/*******************************************************************
 *   > File Name: 11-printdir.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 01:32:19 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth){
    DIR *dp;/*定义一个目录指针*/
    struct dirent *entry;/*定义一个目录信息结构体指针*/
    struct stat statbuf;/*定义一个文件信息结构体*/

    if((dp = opendir(dir)) == NULL){/*打开目录*/
        fprintf(stderr, "Cannot open directory : %s\n",dir);return;
    }

    chdir(dir);/*跳转到该目录*/
    while((entry = readdir(dp)) != NULL){/*读目录信息*/
        lstat(entry -> d_name, &statbuf);/*获得目录下文件的信息*/
        if(S_ISDIR(statbuf.st_mode)){/*是否是目录*/
            if(strcmp(".", entry -> d_name) == 0 || strcmp("..", entry -> d_name) == 0)/*ignore ".",".."*/
                continue;
            printf("%*s%s/\n",depth, " ", entry -> d_name);
            printdir(entry->d_name, depth+4);/*递归*/
    }else
        printf("%*s%s\n",depth," ",entry -> d_name);
    }

    chdir("..");

    closedir(dp);
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage : %s <DIR>\n",argv[0]);return -1;
    }

    printf("Directory scan of %s:\n",argv[1]);
    printdir(argv[1],0);
    printf("done.\n");

    return 0;
}
