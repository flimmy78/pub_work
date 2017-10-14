#include <stdio.h>
#include <math.h>

#define NONE "\033[m"

#define RED "\033[0;32;31m"

#define LIGHT_RED "\033[1;31m"

#define GREEN "\033[0;32;32m"

#define LIGHT_GREEN "\033[1;32m"

#define BLUE "\033[0;32;34m"

#define LIGHT_BLUE "\033[1;34m"

#define DARY_GRAY "\033[1;30m"

#define CYAN "\033[0;36m"

#define LIGHT_CYAN "\033[1;36m"

#define PURPLE "\033[0;35m"

#define LIGHT_PURPLE "\033[1;35m"

#define BROWN "\033[0;33m"

#define YELLOW "\033[1;33m"

#define LIGHT_GRAY "\033[0;37m"

#define WHITE "\033[1;37m"


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
		printf(GREEN"*"NONE);				/* 圆的左侧 */
		for(; x < 30+m; x++)		/* 圆形的空心控制部分 */
			printf(" ");			
		printf(GREEN"*\n"NONE);				/* 圆的右侧 */
	}

    return 0;
}
