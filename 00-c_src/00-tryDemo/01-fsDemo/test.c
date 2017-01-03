#include <stdio.h>

int main(void)
{
    char byte;
    int i;
    int arr[8] = {0};

    byte = 5;

    for(i = 0; i < 8; i++)
    {
        arr[i] = (byte >> i)&(0x01);
    }
    
    for(i = 7; i >= 0; i--)
    {
        printf("%d",arr[i]);
    }
    puts("");

    return 0;
}
