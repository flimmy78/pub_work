#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(int argc,char **argv)
{
    if(argc != 2){
	fprintf(stderr,"Usage:%s [fifo_name]\n",argv[0]);
	exit(1);
    }

    if(mkfifo(argv[1],0666) < 0){
	perror("mkfifo");
	exit(1);
    }
    return 0;
}
