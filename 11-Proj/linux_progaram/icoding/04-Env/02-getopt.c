/*******************************************************************
 *   > File Name: 02-getopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 11:31:15 AM CST
 ******************************************************************/
#if (0)
 
#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int opt;

    int i;
    for(i = 0; i< argc; i++){
        printf("argv[%d] :%s\n",i,argv[i]);
    }
	
	while((opt = getopt(argc, argv, ":if:ls")) != -1){
		switch(opt){
			case 'i':
			case 'l':
			case 'r':
				printf("option :%c\n",opt);break;
			case 'f':
				printf("filename :%s\n", optarg);break;
			case ':':
				printf("option needs a value\n");break;
			case '?':
				printf("unknown option : %c\n",optopt);break;
			}
	}
	for(;optind < argc; optind ++)
		printf("argument :%s\n",argv[optind]);
	
    return 0;
}
