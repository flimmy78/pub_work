/*******************************************************************
 *   > File Name: 01-args.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Mar 2017 10:49:05 AM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int arg;
	
	for(arg = 0; arg < argc; arg ++){
		if(argv[arg][0] == '-')
			printf("option :%s\n",argv[arg] + 1);
		else
			printf("argument %d :%s\n",arg,argv[arg]);
	}
	
    return 0;
}
