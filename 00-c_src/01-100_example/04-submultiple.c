#include <stdio.h>

int main(void)
{
	long i;		/* 使用长整形变量，以免超出整数的表示范围 */
	int j;

	printf("Please input number :");
	scanf("%ld",&i);

	for(j = 999; j >= 100; j--)	/* 所有的约数的可能取值是从999到100，j从大到小 */
	{
		if(i % j == 0)			/* 若是约数，则输出结果 */
		{
			printf("The max factor with 3 digits in %ld is : %d.\n",i,j);
			break;
		}
	}

    return 0;
}
