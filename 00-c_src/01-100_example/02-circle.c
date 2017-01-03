#include <stdio.h>
#include <math.h>

int  main()
{
	double y;
	int x, m;

	for(y = 10; y >= -10; y--)	/* 圆的半径为10 */
	{
		m = 2.5 * sqrt(100 - y*y);	/* 计算y对应的坐标m，\
									   2.5是屏幕纵横比调节系数，\
									   因为屏幕的行距大于列距，\
									   不进行调节显示出来的将是椭圆 */

		for(x = 1; x < 30-m ; x++)	/* 图形左侧空白控制 */
			printf(" ");
		printf("*");				/* 圆的左侧 */
		for(; x < 30+m; x++)		/* 圆形的空心控制部分 */
			printf(" ");			
		printf("*\n");				/* 圆的右侧 */
	}

    return 0;
}
