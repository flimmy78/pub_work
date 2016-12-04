#include <stdio.h>

#define DEBUG_TEST 
/*SHUT_UP_DOWN_IDLE=0*/
//char SHUT_UP_DOWN_IDLE = 0;
//volatile char shut_up_down = SHUT_UP_DOWN_IDLE;
volatile char shut_up_down = 0;

void gk_set_shut_up_down(char flag)
{
	shut_up_down = flag;
}

char gk_get_shut_up_down(void)
{
	return shut_up_down;
}

#ifdef DEBUG_TEST
int main(void)
{
	int value ;

	value = gk_get_shut_up_down();
	printf("We got shut_up_down : %d \n",value);
	gk_set_shut_up_down(100);
	value = gk_get_shut_up_down();
	printf("We set shut_up_down : %d \n",value);

	return 0;
}
#endif
