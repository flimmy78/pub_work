/*******************************************************************
 *   > File Name: 97-fputs.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Mar 2017 11:32:13 PM CST
 ******************************************************************/
#if (0)
int fputc(int c, FILE *stream);

int fputs(const char *s, FILE *stream);

int putc(int c, FILE *stream);

int putchar(int c);

int puts(const char *s);
/*--------------------------------*/
int fgetc(FILE *stream);

char *fgets(char *s, int size, FILE *stream);

int getc(FILE *stream);

int getchar(void);

char *gets(char *s);

int ungetc(int c, FILE *stream);

#endif


#include <stdio.h>

int main(int argc, char* argv[])
{
    int c;

    while(1){
        c =fgetc(stdin);
        if((c >= '0') && (c <= '9')){
            fputc(c, stdout);
        }
        if(c == '\n'){
            break;
        }
    }
    puts("");

    return 0;
}
