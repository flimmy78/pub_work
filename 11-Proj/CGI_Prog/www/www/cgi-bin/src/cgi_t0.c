/*******************************************************************
 *   > File Name: cgi_t0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 20 Mar 2017 01:50:01 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("Contenttype:text/html/n/n");
    printf("<html>/n");
    printf("<head><title>An HTML Page From a CGI</title></head>/n");
    printf("<body>/n");
    printf("<h2>This is an HTML page generated from with in a CGI program...</h2>/n");
    printf("<hr><p>/n");
    printf("<a href="../output.html#two"><b>Go back to out put.html page </b></a>/n");
    printf("</body>/n");
    printf("</html>/n");
    fflush(stdout);

    return 0;
}
