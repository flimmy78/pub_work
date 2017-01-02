#include <stdio.h>

#define DEBUG

#define BIG_ENDIAN (1)	/*大端序*/
#define LITTLE_ENDIAN (0)	/*小端序*/

int BigOrLittle_endian(void)
{
	unsigned int word = 0x12345678;

	unsigned char byte0 = *((unsigned char *)&word);
#if 0
	unsigned char byte1 = *((unsigned char *)&word+1);
	unsigned char byte2 = *((unsigned char *)&word+2);
	unsigned char byte3 = *((unsigned char *)&word+3);

	printf("\n%hhx\n",byte0);
	printf("%hhx\n",byte1);
	printf("%hhx\n",byte2);
	printf("%hhx\n\n",byte3);
#endif

	if(byte0 == 0x12)
	{
		printf("该机器是大端序！\n");
		return BIG_ENDIAN;
	}
	else
	{
		printf("该机器是小端序！\n");
		return LITTLE_ENDIAN;
	}
}

int BigOrLittle_endian_(void)
{
    union ENDIAN
    {
        int word = 0x12345678;
        char byte ;
    }ENDIAN_;

    byte = 
}

#ifdef DEBUG
int main(void)
{
	int ret;

	ret = BigOrLittle_endian();

	printf("ret = %d\n",ret);

	return 0;
}
#endif
