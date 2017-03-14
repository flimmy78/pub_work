/*******************************************************************
 *   > File Name: 02-argopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Mar 2017 09:27:11 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int opt;

    while((opt = getopt(argc, argv, ":if:lr")) != -1){
        switch(opt){
            case 'i':
            case 'l':
            case 'r':
                printf("option :%c\n", opt);break;
            case 'f':
                printf("filename :%s\n", optarg);break;
            case ':':
                printf("option neads a value\n");break;
            case '?':
                printf("unknown option: %c\n", optopt);break;
        }
    }

    for(;optind < argc; optind ++){
        printf("argument :%s\n",argv[optind]);
    }

    return 0;
}
