#include <stdio.h>

int main(int argc, char *argv[])
{
        short a = 1;
        char endian = (char)a;


        if(endian > 0)
        {
                printf("this is small endian\n");
        }else
        {
                printf("this is big endian\n");
        }

        printf("convert %d to big endian %d\n", a, htons(a));


        return 0;
}
