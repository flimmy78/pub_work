#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    FILE *fp;
    char ch;
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    fp = fopen(argv[1],"r+");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 
    
    //while((ch = fgetc(stdin)) != '#')
    while((ch = fgetc(fp)) != EOF)
	putchar(ch);

    return 0;
}
