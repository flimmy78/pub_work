#include <stdio.h>

int main(void)
{
	int day;

	while(1){
		scanf("%d",&day);
		if(day == 1){
			printf("今天是周一\n");
		}else if(day == 2){
			printf("今天是周二\n");
		}else if(day == 3){
			printf("今天是周三\n");
		}else if(day == 4){
			printf("今天是周四\n");
		}else if(day == 5){
			printf("今天是周五\n");
		}else if(day == 6){
			printf("今天是周六\n");
		}else if(day == 7){
			printf("今天是周日\n");
		}else{
			printf("输入错误，重新输入!\n");
		}
	}
	return 0;
}
