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


int main()
{
	double y;
	int x,m;

	for(y = 1; y >= (-1); y -= 0.1)	/* y为列方向，值从1到-1，步长为0.1 */
	{
		m = acos(y) * 10;	/* 计算出y对应的弧度m，乘10为图形放大倍数 */
		for(x = 1; x < m; x++)	
			printf(PURPLE"+"NONE);
		printf(GREEN"*"NONE);		/*控制打印左侧的*号 */
		for(; x < 62-m; x++)
			printf("-");
		printf(GREEN"*"NONE);		/* 控制打印同一行中对称的右侧* */
		for(x = 1; x < m; x++)	
			printf(PURPLE"+"NONE);
        puts("");
	}

    return 0;
}
