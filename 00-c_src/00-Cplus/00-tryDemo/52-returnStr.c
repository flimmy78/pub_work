/*******************************************************************
 *   > File Name: 01-returnStr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Sep  7 17:02:25 2017
 ******************************************************************/

#include <stdio.h>

char *returnStr(void){
    char *str="123456789";

    return str;
}

int main(int argc, char* argv[])
{
    printf("%s\n", returnStr());

    return 0;
}
