/*******************************************************************
 *   > File Name: 01-strerror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 29 Aug 2017 11:22:07 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    FILE *fp;

    if((fp = fopen("1.txt", "r")) == NULL){
        printf("Fopen 1.txt error : %s\n", strerror(errno));
        return (-1);
    }

    fclose(fp);

    return 0;
}
