#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main(int argc,char **argv)
{
    FILE *read_fp,*write_fp;
    char buf[SIZE];
    if(argc != 3){
	printf("Uage: %s [file_path] [file_path]\n",argv[0]);
	exit(1);
    }
    if((read_fp = fopen(argv[1],"r")) == NULL){
	perror("fopen");
	exit(1);
    } 
    if((write_fp = fopen(argv[2],"w")) == NULL){
	perror("fopen");
	exit(1);
    } 

    //用fgets和fputs实现文件的拷贝
    while(fgets(buf,SIZE,read_fp) != NULL){
	    fputs(buf,write_fp);
	    fprintf(stdout,"%s",buf);
    }
    return 0;
}
