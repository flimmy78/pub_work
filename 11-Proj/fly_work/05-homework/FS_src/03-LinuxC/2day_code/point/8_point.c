#include <stdio.h>
#include <stdlib.h>

typedef int (*ARRTYPE)[3];

int main(void)
{
    int (*p)[3];
    int i,j;
    p = (ARRTYPE)malloc(2*3*sizeof(int));
    if(NULL == p){
	printf("malloc failed!\n");
	exit(1);
    }
    for(i = 0; i < 2; i++)
	for(j = 0; j < 3; j++)
	    p[i][j] = i+j+1;
    for(i = 0; i < 2; i++){
	for(j = 0; j < 3; j++)
	    printf("%d\t",p[i][j]);
	printf("\n");
    }
    return 0;
}
