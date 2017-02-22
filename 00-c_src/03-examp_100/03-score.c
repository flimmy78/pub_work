#include <stdio.h>

int main(void)
{
	int integer, i, max, min, sum;
	max = -32768;	/* 先假设当前的最大值max为C语言整型数的最小值 */
	min = 32768;	/* 先假设当前的最小值min为C语言整型数的最大值 */
	sum = 0;

	for(i = 1; i <= 10; i++)	/* 将求累加和变量的初值置为0 */
	{
		printf("Input number %d = ",i);
		scanf("%d",&integer);	/* 输入评委的评分 */
		sum += integer;			/* 计算总分 */
		if(integer > max)		/* 通过比较筛选出其中的最高分 */
			max = integer;		
		if(integer < min)		/* 通过比较筛选出其中的最低分 */
			min = integer;
	}
	printf("Canceled max score : %d\nCanceled min score : %d\n",max,min);
	printf("Average score :%d\n",(sum-max-min)/8);

	return 0;
}


