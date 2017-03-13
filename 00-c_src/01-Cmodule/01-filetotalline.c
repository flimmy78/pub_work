/*******************************************************************
 *   > File Name: 01-fileline.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 06:02:17 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int fileline(const char *filepathname){
    int line = 0;
    char buf[128];
    FILE* fp;

    if(filepathname == NULL){
        fprintf(stderr, "No such file\n");return (-1);
    }

    if((fp = fopen(filepathname, "r")) == NULL){
        fprintf(stderr, "Fopen file err\n");return (-1);
    }

    while(fgets(buf, 128, fp) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            line ++;
    }
    return line;
}

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2){
        printf("\n\t\tUsage : %s <filepathname> \n\n",argv[0]);exit(EXIT_FAILURE);
    }
    
    printf("The total line of %s: %d\n",argv[1], fileline(argv[1]));
    return 0;
}
