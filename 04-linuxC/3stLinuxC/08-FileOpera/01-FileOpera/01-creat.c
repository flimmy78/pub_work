/*******************************************************************
 *   > File Name: 01-creat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 09:07:29 2017
 ******************************************************************/
#if (0)
int creat(const char *pathname, mode_t mode);//建立文件
//creat（） 无法建立特别的装置文件，如果需要请使用 mknod（）
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define PATHNAME    "./test.file"
#define MODE        0777

int main(int argc, char* argv[])
{
    int ret;

    ret = creat(PATHNAME, MODE);
    if(ret < 0){
        printf("ret = %d\n", ret);
        perror("creat ");exit(EXIT_FAILURE);
    }

    printf("ret = %d , creat %s ok !\n",ret, PATHNAME);

    return 0;
}
