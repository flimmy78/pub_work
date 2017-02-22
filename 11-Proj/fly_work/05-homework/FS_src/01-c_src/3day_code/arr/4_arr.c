#include <stdio.h>


int main(void)
{
	int a[5],i;

	//a = {1,2,4,3,5};  //err
	//a[5] = {1,2,3,4,5};  //err
	for(i = 0;i < 5; i++)
		//a[i] = i+1;
		scanf("%d",&a[i]);
	for(i = 0;i < 5; i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
