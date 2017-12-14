/*******************************************************************
 *   > File Name: 01-perror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 29 Aug 2017 10:43:49 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;   //定义一个文件指针

    if((fp = fopen("1.txt","r")) == NULL){
        perror("Open 1.txt error :");   //输出错误信息
        return (-1);
    }else{
        printf("Open 1.txt successed , fp = %p\n", fp);
    }

    fclose(fp);

    return 0;
}
