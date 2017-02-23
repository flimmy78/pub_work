#include <stdio.h>

int main(void)
{
	int a,ret;
	float b;
	double c;

	//scanf("a=%d,b=%f",&a,&b);
	ret = scanf("%d%f%lf",&a,&b,&c);
	printf("ret = %d\n",ret);
	printf("a = %d,b = %f,c = %f\n",a,b,c);

	return 0;
}
