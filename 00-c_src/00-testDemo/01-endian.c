#include <stdio.h>
#include <stdbool.h>

#define DEBUG_TEST

enum endian
{
	Big_endian,		/* 0，大端序 */		
	Little_endian	/* 1，小端序 */
};

/*********************************************************
  *@function:判断一个机器是不是小端序
  *@param(in):无(void)
  *@return:布尔型：返回1，小段序；返回0，大端序；
  *******************************************************/
#ifndef UNION_ENDIAN
bool isLittle_endian(void)
{
	unsigned int word = 0x12345678;

	unsigned char byte0 = *((unsigned char *)&word + 0);
#ifndef DEBUG_TEST
	unsigned char byte1 = *((unsigned char *)&word + 1);
	unsigned char byte2 = *((unsigned char *)&word + 2);
	unsigned char byte3 = *((unsigned char *)&word + 3);

	unsigned int *Pint = &word;
	unsigned char *Pchar0 = &byte0;
	unsigned char *Pchar1 = &byte1;
	unsigned char *Pchar2 = &byte2;
	unsigned char *Pchar3 = &byte3;

	printf("%p : word  = 0x%x\n",Pint,word);
	printf("%p : byte0 = 0x%x\n",Pchar0,byte0);
	printf("%p : byte1 = 0x%x\n",Pchar1,byte1);
	printf("%p : byte2 = 0x%x\n",Pchar2,byte2);
	printf("%p : byte3 = 0x%x\n",Pchar3,byte3);
#endif

	if(byte0 == 0x78)
	{
		//printf("little endian\n ");
		return (Little_endian);
	}
	else
	{
		//printf("big endian\n");		
		return (Big_endian);
	}
}
#else
bool isLittle_endian(void)
{
	union A
	{
		unsigned int word;
		unsigned char byte;
	};

	union A un;
	un.word = 0x12345678;
	if(un.byte == 0x78)
	{
		return (Little_endian);
	}
	else
	{
		return (Big_endian);
	}
}
#endif



#ifdef DEBUG_TEST
int main(void)
{
	bool ret;

	ret = isLittle_endian();
	if(ret == 0)
	{
		printf("ret = %d , big endian machine\n",ret);	
	}
	else
	{
		printf("ret = %d ,little endian machine\n",ret);
	}

	return 0;
}
#endif
