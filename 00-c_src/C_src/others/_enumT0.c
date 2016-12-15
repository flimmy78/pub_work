#include <stdio.h>

enum
{
	SHUT_UP_DOWN_IDLE,
	SHUT_UP_HANDLE,
	SHUT_DOWN_HANDLE,
};

int main(void)
{
	printf("SHUT_UP_DOWN_IDLE = %d\n",SHUT_UP_DOWN_IDLE);
	printf("SHUT_UP_HANDLE = %d\n",SHUT_UP_HANDLE);
	printf("SHUT_DOWN_HANDLE = %d\n",SHUT_DOWN_HANDLE);

	return 0;
}
