#include <stdio.h>


int main(void)
{
#if 0
    int a = 1,b=3,c=5,d=7;
    int *arr[4] = {&a,&b,&c,&d};   //arr为指针数组
#else
    int array[] = {11,12,13,14};
    int *arr[4] = {array,array+1,array+2,array+3};   //arr为指针数组
#endif
    int i;

    for(i = 0; i < 4; i++)
	printf("%d\n",*arr[i]);
    return 0;
}
