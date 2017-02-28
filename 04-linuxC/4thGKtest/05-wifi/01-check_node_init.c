/*******************************************************************
 *   > File Name: 01-check_node_init.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Feb 2017 01:41:48 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define PATH "/proc/wifi_error"
#define MODE "r"

static FILE *wifi_node = NULL;

static int check_node_init(void){
    if((wifi_node = fopen(PATH, MODE)) == NULL){
        printf("Open /proc/wifi_error Failed ! Reason :%s\n",(char *) strerror(errno));return EXIT_FAILURE;
    }
}

int main(int argc, char* argv[])
{
    check_node_init();

    return 0;
}
