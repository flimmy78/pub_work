#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char **argv)
{

    DIR * dp;
    struct dirent *drp;

    if(argc != 2){
	fprintf(stdout,"Usage: %s [path]\n",argv[0]);
	exit(1);
    }
    
    if((dp = opendir(argv[1])) ==NULL){
	perror("opendir");
	exit(1);
    }

    while((drp = readdir(dp)) != NULL){
	printf("%s\n",drp->d_name);
    }
    
    return 0;
}
