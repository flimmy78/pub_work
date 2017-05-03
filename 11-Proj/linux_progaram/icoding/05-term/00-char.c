/*******************************************************************
 *   > File Name: 00-char.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 02 May 2017 11:44:11 AM CST
 ******************************************************************/

#include <stdio.h>

char *menu[] = {
    "a - add new record",
    "b - delete record",
    "q - quit",
    NULL
};

int main(int argc, char* argv[])
{
#if (1)
    printf("%s\n", *menu);
    //printf("%s\n", *menu + 1);
    printf("%s\n", *(menu + 1));
    printf("%s\n", *(menu + 2));
    //printf("%s\n", *(menu + 3));
    if((*(menu + 3)) == NULL){
        puts("\tEnd");
    }
#else
    
#endif

    return 0;
}
