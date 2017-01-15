/*******************************************************************
 *   > File Name: 07-ftell.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 03:02:08 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    FILE* fp;

    if(argc < 2)
    {
        printf("Usage : %s <file> \n",argv[0]);
        return (-1);
    }
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("Fail to fopen");
        return (-1);
    }
    fseek(fp,0,SEEK_END);
    printf("The size of %s is %ld\n",argv[1], ftell(fp));

    return 0;
}
