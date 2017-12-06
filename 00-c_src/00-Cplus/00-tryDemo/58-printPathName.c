/*******************************************************************
 *   > File Name: 58-printPathName.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Oct 26 17:09:27 2017
 ******************************************************************/

#include <stdio.h>
#include <string.h>

char PATH_NORMAL[60] = "A:/VIDEO/NORMAL/2017_1026_121317_001.MOV";
char PATH_EVENT[60] =  "A:/VIDEO/EVENT/2017_1026_123817_008.MOV";

int main(int argc, char* argv[])
{
    int i = 0;

    for(i = 0; i < strlen(PATH_NORMAL); i++){
        printf("[%2d] :%c\t%c\n", i, PATH_NORMAL[i], PATH_EVENT[i]);
    }

    puts(PATH_NORMAL);
    puts(PATH_EVENT);

    return 0;
}
