/*******************************************************************
 *   > File Name: 29-makeword.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 18 Apr 2017 03:58:14 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *makeword(char *line, char stop){
    int x= 0, y;
    char *word = (char*)malloc(sizeof(char) * (strlen(line) + 1));

    for(x = 0; ((line[x]) && (line[x] != stop)); x++){
        word[x] = line[x];
    }

    word[x] = '\0';
    if(line[x])
        ++x;
    y = 0;
    while(line[y++] = line[x++]);
    return word;
}

int main(int argc, char* argv[])
{
    char *test_str = "http://192.168.1.170/cgi-bin/cgi-test.cgi?param1+param2+param3";
    char S = '+';
    printf("%s\n", test_str);
    printf("%s\n",makeword(test_str, S));

    return 0;
}
