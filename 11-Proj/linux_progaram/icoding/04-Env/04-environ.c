/*******************************************************************
 *   > File Name: 04-environ.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Mar 2017 10:16:16 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *var, *value;

    if(argc == 1 || argc > 3){
        fprintf(stderr , "Usage : envison var [value]\n");exit(1);
    }

    var = argv[1];
    value = getenv(var);
    if(value)
        printf("Variable %s has value %s\n", var, value);
    else
        printf("variable %s has no value\n", var);

    if(argc == 3){
        char *string;
        value = argv[2];
        string = (char *)malloc(strlen(var) + strlen(value) + 2);/*申请空间*/
        if(!string){    /*申请失败*/
            fprintf(stderr, "out of memory\n");exit(1);
        }

        /* 构造"名字 = 值"的字符串*/
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        
        /*设置变量的值*/
        printf("Calling putenv with: %s\n", string);
        if(putenv(string) != 0){
            fprintf(stderr, "putenv failed\n");
            free(string);exit(1);
        }

        /*查看变量的新值*/
        value = getenv(var);
        if(value)
            printf("New value of %s is %s\n", var, value);
        else
            printf("New value of %s is NULL ???\n",var);
        /*环境仅对程序本身有效，不会反映到外部环境中*/
    }

    return 0;
}
