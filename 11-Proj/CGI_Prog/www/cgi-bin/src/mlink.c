/*******************************************************************
 *   > File Name: mlink.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Mar 2017 06:52:09 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10000

typedef struct{
    char *name;
    char *val;
}entry;

int num_value = 0;
entry entries[MAX_ENTRIES];
char *makeword(char *line, char stop);
char *fmakeword(FILE *f, char stop, int *len);
cahr x2c(char *what);
void unescape_url(char *url);
void plustospace(char *str);
void getcgivalue(char *buf, char *s);

int main(int argc, char* argv[])
{
    return 0;
}
