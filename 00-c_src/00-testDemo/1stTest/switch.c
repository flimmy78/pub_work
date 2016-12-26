#include <stdio.h>

int main(void)
{
	int day;

	printf("Pls input a day number :");
	scanf("%d",&day);

	switch(day)
	{
		case 1:
			printf("今天是星期一！\n");
			break;
		case 2:
			printf("今天是星期二！\n");
			break;
		case 3:
			printf("今天是星期三！\n");
			break;
		case 4:
			printf("今天是星期四！\n");
			break;
		case 5:
			printf("今天是星期五！\n");
			break;
		case 6:
			printf("今天是星期六！\n");
			break;
		case 7:
			printf("今天是星期日！\n");
			break;
		default:
			printf("输入错误，重新输入！\n");
	}

	return 0;
}
