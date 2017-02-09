/*******************************************************************
 *   > File Name: 03-sizeof.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 11:31:52 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int size;
    size = sizeof "test.txt";

    printf("size = %d\n",size);
    
    char *pathname;
    pathname = (char*)malloc(size);
    pathname = "test.txt";
    printf("pathname :%s\n",pathname);

    return 0;
}
