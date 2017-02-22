#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    FILE *read_fp,*write_fp;

    if(argc != 3){
	fprintf(stderr,"Usage: %s [src_file] [des_file]\n",argv[0]);
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

    char ch;
    int len,i;



    fseek(read_fp,-2,SEEK_END);
    len = ftell(read_fp);
    for(i = 0; i <= len; i++){
	ch = fgetc(read_fp);
	fseek(read_fp,-2,SEEK_CUR);
	fputc(ch,write_fp);
	putchar(ch);
    }
    fputc('\n',write_fp);    //文件末尾加'\n'
    fclose(read_fp);
    fclose(write_fp);
    return 0;
}
