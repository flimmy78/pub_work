#include <stdio.h>

int main(void)
{
	int i, x, y, last = 1;		/* 变量last保存求X的Y次方过程中的部分积的后三位 */
	printf(" Input X and Y (X**Y) :");	
	scanf("%d**%d",&x,&y);
	for(i = 1; i <= y; i++)		/* X自乘Y次 */
		last = last * x % 1000;	/* 将last乘X后对1000取模，即求积的后三位 */
	printf("The last 3 digits of %d**%d is : %d\n",x,y,last%1000);	/* 打印结果 */
}
