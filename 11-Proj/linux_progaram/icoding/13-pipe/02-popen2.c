/*******************************************************************
 *   > File Name: 02-popen2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 11:52:37 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{   
    FILE *write_fp;
    char buffer[BUFSIZ + 1];

    sprintf(buffer, "Once upon a time, there was ...\n");
    write_fp = popen("od -c ", "w");
    if(write_fp != NULL){
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }

    exit(EXIT_FAILURE);
}
