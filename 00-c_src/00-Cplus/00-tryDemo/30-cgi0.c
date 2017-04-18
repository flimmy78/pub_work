/*******************************************************************
 *   > File Name: 30-cgi0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 18 Apr 2017 04:38:38 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int i,n;
    
    printf("Contenttype:text/plain\n\n");
    n = 0;

    if(getenv("CONTENT-LENGTH"))
        n = atoi(getenv("CONTENT-LENGTH"));
    for(i = 0; i<n; i++)
        putchar(getchar());
    putchar(n);
    fflush(stdout);

    return 0;
}
