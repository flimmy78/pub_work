/*******************************************************************
 *   > File Name: 03-strerror.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 11:36:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define FILEPATH "./1.txt"

int main(void)
{
    FILE* fp;

    if((fp = fopen(FILEPATH,"r")) == NULL)
    {
        printf("Open %s fail : %s\n",FILEPATH,strerror(errno));
        return (-1);
    }
    fclose(fp);

    return 0;
}
