/*******************************************************************
 *   > File Name: 05-memory5a.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 05:57:48 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *some_memory = (char *)0;
    
    /*read the NULL pointer*/
    printf("A read from null %s\n", some_memory);   //A read from null (null)
    /*write some massage to the NULL pointer*/   
    sprintf(some_memory, "A write to null\n");      //Segmentation fault (core dumped)

    return 0;
}
