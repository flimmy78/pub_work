#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    FILE *read_fp,*write_fp;
    char ch;
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

    //用fgetc和fputc实现文件的拷贝
    while((ch = fgetc(read_fp)) != EOF){
	    fputc(ch,write_fp);
	    putchar(ch);
    }
    return 0;
}
