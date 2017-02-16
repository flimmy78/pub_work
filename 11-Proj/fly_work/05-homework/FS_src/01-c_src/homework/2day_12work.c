//12、编写一个函数my_power，用循环的方法实现返回一个float类型数的某个整数次幂(保留6位小数)。如调用my_power(3.14,-2)返回0.101424

#include <stdio.h>

float my_power(float a,int n)
{
	float x = 1;
	int i;

	if(n == 0)
		x =  1.0;
	else if(n > 0){
		for(i = 0; i < n;i++)
			x *= a;
	}else{
		for(i = 0; i > n; i--)
			x *= a;
		x = 1/x;
	}
	return x;
}

int main(void)
{
	float a;
	int n;
	scanf("%f%d",&a,&n);

	printf("%f\n",my_power(a,n));

	return 0;
}
