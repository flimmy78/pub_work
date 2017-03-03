/*******************************************************************
 *   > File Name: 08-copy_stdio.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 11:25:10 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
/*INC for errno*/
#include <errno.h>

int main(int argc, char* argv[])
{
#if (0)
    int c;
    FILE *in, *out;

    in = fopen("file.in","r");
    out = fopen("file.out","w");

    while((c = fgetc(in)) != EOF)
        fputc(c, out);
#else
    int c;
    FILE *in, *out;

    if(argc < 3){
        printf("Usage: %s  <file.in>  <file.out>\n",argv[0]);return (-1);
    }

    /*以可读方式打开源文件，文件必须存在*/
    if((in = fopen(argv[1], "r")) == NULL){
        perror("fopen file err");return (errno);
    }

    /*以可写方式打开目标文件，文件存在，长度截为0；不存在，则创建*/
    if((out = fopen(argv[2], "w")) == NULL){
        perror("fopen file err");return (errno);
    }
    
    /**/
    while((c = fgetc(in)) != EOF){
        fputc(c, out);
    }


#endif

    return 0;
}
