#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool bl;

#if 0
	bl = 100;
	printf("bl = %d\n",bl);
	bl = -100;
	printf("bl = %d\n",bl);
	bl = 0;
	printf("bl = %d\n",bl);
#endif

	printf("Pls input:");
	scanf("%d",(int *)&bl);

#if 0
	if(bl != 0)
	{
		bl = true;
	}
	else
	{
		bl = false;
	}
#else
	bl = (bl != 0) ? true:false;
#endif

	printf("bl = %d\n",bl);

	return 0;
}
