#include<stdlib.h>
#include<stdio.h>
int main()
{
    char *string, *stopstring;
    double x;
    int base;
    long l;
    unsigned long ul;

    string = "3.1415926 This stopped it";
    x = strtod(string, &stopstring);
    printf("string = %s\n", string);
    printf("strtod = %f\n", x);
    printf("Stopped scan at: %s\n\n", stopstring);

    string = "-1011 This stopped it";
    l = strtol(string, &stopstring, 10);
    printf("string = %s\n", string);
    printf("strtol = %ld\n", l);
    printf("Stopped scan at: %s\n\n", stopstring);

    string = "10110134932";
    printf("string = %s\n", string);
    /*Convertstringusingbase2,4,and8:*/
    for(base = 2; base <= 8; base *= 2)
    {
        /*Convertthestring:*/
        ul = strtoul(string, &stopstring, base);
        printf("strtol = %ld(base %d)\n", ul, base);
        printf("Stopped scan at: %s\n", stopstring);
    }

    return 0;
}
