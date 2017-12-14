/*******************************************************************
 *   > File Name: 05-ftell.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 31 Aug 2017 12:25:37 AM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;

    if(argc < 2){
        printf("Usage : %s file \n", argv[0]);
        return (-1);
    }

    if((fp = fopen(argv[1], "r")) == NULL){
        perror("Fail to fopen :");
        return (-1);
    }

    fseek(fp, 0, SEEK_END);

    printf("The size of %s is %ld bytes\n", argv[1], ftell(fp));

    return 0;
}
