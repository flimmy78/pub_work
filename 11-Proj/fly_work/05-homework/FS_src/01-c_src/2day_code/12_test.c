#include <stdio.h>

int main(void)
{
	int day;

	while(1){
		scanf("%d",&day);
		switch(day){
			case 1:
			printf("今天是周一\n");
			case 2:
			printf("今天是周二\n");
			case 3:
			printf("今天是周三\n");
			case 4:
			printf("今天是周四\n");
			case 5:
			printf("今天是周五\n");
			case 6:
			printf("今天是周六\n");
			case 7:
			printf("今天是周日\n");
			default:
			printf("输入错误，重新输入!\n");
		}
	}
	return 0;
}
