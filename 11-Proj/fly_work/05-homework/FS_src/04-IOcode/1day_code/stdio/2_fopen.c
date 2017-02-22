#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    FILE *fp;
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    fp = fopen(argv[1],"r+");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 

    return 0;
}
