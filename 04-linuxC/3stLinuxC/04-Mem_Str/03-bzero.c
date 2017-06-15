/*******************************************************************
 *   > File Name: 03-bzero.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 11:28:46 2017
 ******************************************************************/
#if (0)
void bzero(void *s, int n);
//@FUNC:将一段内存区域全部清为零；
//相当于memset((void*)s, 0, size_t n);
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char s[10] = "abcdef";
    
    printf("%s\n", s);
    int i;

    for(i = 0; s[i] != 0; i++){
        printf("s[i] = %d\n", s[i]);
    }
    //bzero();
    bzero((void*)s, 10);
    for(i = 0; i< 10; i++){
        printf("s[i] = %d\n", s[i]);
    }

    return 0;
}
