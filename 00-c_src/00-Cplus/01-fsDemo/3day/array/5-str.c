/*******************************************************************
 *   > File Name: 5-str.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 05:26:53 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char str[22];
    int i;

    for(i = 0; i< 5; i++){
        //str[i] = 'A' + i;
        //printf("Pls input char :");
        scanf("%c", &str[i]);
    }

    for(i = 0; i< 5; i++){
        printf("%c\t", str[i]);
    }
    puts("");

    strcpy(str, "hello");
    printf("%s\n", str);

    return 0;
}
