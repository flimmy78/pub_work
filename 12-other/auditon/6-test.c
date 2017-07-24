/*******************************************************************
 *   > File Name: 6-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jul 18 20:32:59 2017
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setmemory(char **p, int num){
    *p = (char*)malloc(num);
}

int main(int argc, char* argv[])
{
    char *str = NULL;
    setmemory(&str, 100);
    strcpy(str, "hello");
    printf(str);

    return 0;
}
