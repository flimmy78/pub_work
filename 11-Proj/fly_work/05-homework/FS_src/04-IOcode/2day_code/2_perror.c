#include <stdio.h>

int main(void)
{
    fopen("1.txt","r");
    perror("fopen");
    return 0;
}
