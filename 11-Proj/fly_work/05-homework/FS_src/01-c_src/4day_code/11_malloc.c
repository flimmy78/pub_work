#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p,i;
	
	p = (int*)malloc(sizeof(int)*5);
	if(NULL == p){
		printf("malloc failed!\n");
		exit(1);
	}
	for(i = 0; i < 5; i++)
		scanf("%d",&p[i]);
	for(i = 0; i < 5; i++)
		printf("%d\t",p[i]);
	printf("\n");
	return 0;
}
