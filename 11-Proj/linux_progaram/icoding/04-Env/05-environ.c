/*******************************************************************
 *   > File Name: 05-environ.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 05:23:17 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *var, *value;

    if(argc == 1 || argc > 3){
        fprintf(stderr, "\n\t\tUsage : %s var [value]\n",argv[0]);exit(1);
    }

    var = argv[1];
    value = getenv(var);
    if(value){
        printf("Variable %s has value %s\n",var,value);
    }else{
        printf("variable %s has no value \n",var);
    }

    if(argc == 3){
        char *string;
        value = argv[2];
        string = malloc(strlen(var) + strlen(value) + 2);
        if(!string){
            fprintf(stderr, "out of memory\n");exit(EXIT_FAILURE);
        }
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling  putenv with :%s\n",string);
        if(putenv(string) != 0){
            fprintf(stderr,"");
        }

    }


    return 0;
}
