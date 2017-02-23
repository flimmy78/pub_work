#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p,i;
	
	p = (int*)malloc(5*sizeof(int));
	if(NULL == p){
		printf("malloc failed!\n");
		exit(1);
	}
	for(i = 0; i < 5; i++)
		scanf("%d",&p[i]);
	for(i = 0; i < 5; i++)
		printf("%d\t",p[i]);
	printf("\n");
//	p += 2;
	free(p);
	free(p);  //不能释放已经被释放的空间
	printf("Game Over!\n");

	return 0;
}
