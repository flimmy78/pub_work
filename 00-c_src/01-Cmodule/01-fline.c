/*******************************************************************
 *   > File Name: 01-fline.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 06:02:17 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    /* 获得一个文件的行数 */
unsigned int fline(const char *filepathname){
    static unsigned int line = 0;
    static char buf[128];
    static FILE* fp;
    
    /*传入的文件路径不能为空*/
    if(filepathname == NULL){
        fprintf(stderr, "No such file\n");return (-1);
    }

    /*以可读方式打开文件*/
    if((fp = fopen(filepathname, "r")) == NULL){
        fprintf(stderr, "Fopen file err\n");return (-2);
    }

    while(fgets(buf, 128, fp) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            line ++;    /*累加行数*/
    }
    return line;        /*返回行数*/
}

#define TEST_DEBUG
#ifdef  TEST_DEBUG
int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2){
        printf("\n\t\tUsage : %s <filepathname> \n\n",argv[0]);exit(EXIT_FAILURE);
    }
    
    printf("The total line of %s: %d\n",argv[1], fline(argv[1]));
    return 0;
}
#endif
