#include <stdio.h>
#include <ctype.h>

#define DEBUG_TEST

#if (0)
int isalnum(int c);	/*测试字符是否为字母或者数字*/	   
int isalpha(int c);	/*测试字符是否为英文字母*/    
int isascii(int c);	/*测试字符是否为ascii码字符*/       
int isblank(int c);	/*测试字符是否为Tab键或者空格*/            
int iscntrl(int c);	/*测试字符是否为ascii码控制字符*/        
int isdigit(int c);	/*测试字符是否为阿拉伯数字*/          
int isgraph(int c);	/*测试字符是否为可打印字符*/          
int islower(int c);	/*测试字符是否为小写英文字母*/         
int isprint(int c);	/*测试字符是否为可打印字符*/         
int ispunct(int c);	/*测试字符是否为标点符号或者特殊符号*/           
int isspace(int c);	/*测试字符是否为空格*/         
int isupper(int c);	/*测试字符是否为大写英文字母*/        
int isxdigit(int c);/*测试字符是否为16进制数字*/		 	
#endif

#ifdef DEBUG_TEST
int main(int argc,char **argv)
{
	char str[] = "ABC def\a\b\t\v\f\r123456 !@#$%^&*";
	int i = 0;

	printf("STR:%s\nsizeof(str) = %ld\n",str,sizeof(str));

	/*-----------------------isalnum-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
#if (0)
		if(isalnum(str[i]))
		{
			printf("str[%d] is an alphanumeric character :(%d)-'%c'\n",i,str[i],str[i]);
		}
#else
		if(isalpha(str[i]) || isalnum(str[i]))
		{
			printf("str[%d] is an alphanumeric character :(%d)-'%c'\n",i,str[i],str[i]);
		}
#endif
	}

	/*-----------------------isalpha-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
#if (0)
		if(isalpha(str[i]))
		{
			printf("\tstr[%d] is an alphabetic character :(%d)-'%c'\n",i,str[i],str[i]);
		}
#else
		if(islower(str[i]) || isupper(str[i]))
		{
			printf("---str[%d] is an alphabetic character :(%d)-'%c'\n",i,str[i],str[i]);
		}
#endif
	}

	/*-----------------------isascii-------------------*/
	for(i = 125; i < 130; i++)
	{
		if(isascii(i))
			printf("\tstr is an ascii character :(%d)-'%c'\n",i,i);
		else
			printf("\t\tstr is not an ascii character :(%d)\n",i);
	}

	/*-----------------------isblank-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isblank(str[i]))
		{
			printf("str[%d] is an blank character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}

	/*------------------------iscntrl---------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(iscntrl(str[i]))
		{
			printf("\tstr[%d] is an ascii control character:(%d)\n",i,str[i]);
		}
	}

	/*------------------------isdigit---------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isdigit(str[i]))
		{
			printf("str[%d] is a digit character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}

	/*------------------------isgraph---------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isgraph(str[i]))
		{
			printf("\tstr[%d] is a printable character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}
	
	/*-------------------------isprint-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isprint(str[i]))
		{
			printf("str[%d] is a printable character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}

	/*-------------------------ispunct-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(ispunct(str[i]))
		{
			printf("\t\tstr[%d] icharacter:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}

	/*-------------------------isspace-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isspace(str[i]))
		{
			printf("str[%d] is a space  character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}
		
	/*-------------------------isxdigit-------------------*/
	for(i = 0; str[i] != 0; i++)
	{
		if(isxdigit(str[i]))
		{
			printf("\tstr[%d] is a xdigit character:(%d) - '%c'\n",i,str[i],str[i]);
		}
	}


	return 0;
}
#endif


