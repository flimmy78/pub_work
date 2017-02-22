#include <stdio.h>
#include <math.h>

int main()
{
	double y;
	int x, m, n, yy;

	for(yy = 0; yy <= 20; yy++)	/* 对于每一个y坐标进行计算并在一行中打印图形 */
	{
		y = 0.1*yy;				/* y：屏幕行方向坐标 */
		m = acos(1 - y) *10;	/* m：cos（x）曲线上y点对应的屏幕列坐标 */
		n = 45*(y-1) + 31;		/* n：直线上y点对应的屏幕列坐标 */
				
		for(x =	0; x <= 62; x++)	/* x：屏幕列方向坐标 */
		{			
			if(x ==	m && x==n)		/* 直线与cos（x）相交时打‘+’ */
				printf("+");
			else if(x == n)			/* 打印不相交时的直线图形 */
				printf("+");
			else if(x == m || x == 62 - m)	/* 打印不相交时的cos（x）图形 */
				printf("*");
			else							/* 其他情况打印空格 */
				printf(" ");
		}
		printf("\n");
	}

    return 0;
}
