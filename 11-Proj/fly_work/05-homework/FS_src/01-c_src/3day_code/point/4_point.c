#include <stdio.h>

int main(void)
{
	int a[10];
	int *pa1 = &a[8],*pa2 = &a[3];
	printf("pa1 = %p,pa2 = %p\n",pa1,pa2);
	printf("pa1 - pa2 = %d\n",pa1 - pa2);

	short b[10];
	short *pb1 = &b[8],*pb2 = &b[3];
	printf("pb1 = %p,pb2 = %p\n",pb1,pb2);
	printf("pb1 - pb2 = %d\n",pb1 - pb2);

	double c[10];
	double *pc1 = &c[8],*pc2 = &c[3];
	printf("pc1 = %p,pc2 = %p\n",pc1,pc2);
	printf("pc1 - pc2 = %d\n",pc1 - pc2);
	return 0;
}
