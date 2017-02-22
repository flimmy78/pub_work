#include <stdio.h>
#include <string.h>
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

    //用fread和fwrite实现文件的拷贝
    while(!feof(read_fp) && !ferror(read_fp)){
	    bzero(buf,SIZE);
	    fread(buf,1,SIZE,read_fp);
	    fwrite(buf,1,strlen(buf),write_fp); 
	    printf("%s",buf);
    }
    return 0;
}
