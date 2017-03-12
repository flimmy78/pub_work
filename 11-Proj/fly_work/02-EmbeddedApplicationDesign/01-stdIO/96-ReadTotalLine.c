/*******************************************************************
 *   > File Name: 96-ReadTotalLine.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 12 Mar 2017 10:51:09 PM CST
 ******************************************************************/
#if (0)
char *fgets(char *s, int size, FILE *stream);
#endif

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int line = 0;
    char buf[128];
    FILE * fp;

    if(argc > 2 || argc < 2){
        printf("Usage : %s <filename>\n", argv[0]);return (-1);
    }

    if((fp = fopen(argv[1], "r")) == NULL){
        perror("fopen file err");return (errno);
    }

    while((fgets(buf ,128 , fp)) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            line++;
    }
    printf("The line of %s is %d\n",argv[1], line);

    return 0;
}
