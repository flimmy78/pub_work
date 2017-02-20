#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};

    int **p;
    int i;
    p = (int**)malloc(5*sizeof(*p));
    if(NULL == p){
	printf("malloc failed!\n");
	exit(1);
    }
    for(i = 0; i < 5; i++)
	p[i] = a+i;
    for(i = 0; i < 5; i++)
	printf("%d\t",*p[i]);
    printf("\n");
    return 0;
}
