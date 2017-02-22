#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    fclose(stderr);
    fprintf(stdout,"test stdout\n");
    fprintf(stderr,"test stderr\n");
    return 0;
}
