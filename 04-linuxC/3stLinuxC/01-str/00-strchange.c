/*Note:传给函数的第二个参数，被匹配后，会执行相应的函数，进行特定
 *的功能
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#if 0
#include <stdlib.h>
	double atof(const char *nptr);		/*将字符串转换成浮点型数*/
	int atoi(const char *nptr);			/*将字符串转换成整型数*/
	long atol(const char *nptr);		/*将字符串转换成长整型数*/
	long long atoll(const char *nptr);	/**/
	long long atoq(const char *nptr);	/**/
	char *gcvt(double number, size_t ndigit, char *buf);	/*将浮点型数转换为字符串，取四舍五入*/
	double strtod(const char *nptr, char **endptr);			/*将字符串转换成浮点数*/
	float strtof(const char *nptr, char **endptr);			/**/
	long double strtold(const char *nptr, char **endptr);	/**/
	long int strtol(const char *nptr, char **endptr, int base);	/*将字符串转换成长整型数*/
	long long int strtoll(const char *nptr, char **endptr, int base);	/**/
	unsigned long int strtoul(const char *nptr, char **endptr, int base);	/*将字符串转换成无符号长整型*/

	unsigned long long int strtoull(const char *nptr, char **endptr,int base);

#include <ctype.h>
	int toascii(int c);		/*将整型数转换成合法的ASCII码字符*/
	int toupper(int c);		/*将大写字母转换成小写字母*/
	int tolower(int c);		/*将小写字母转换成大写字母*/
#endif

#define DEBUG_TEST
//#define DEBUG_TEST_0
#define NAMELENGTH 10

#ifdef DEBUG_TEST
int main(int argc,char *argv[])
{
	char func[][NAMELENGTH] = {"atof","atoi","atol","gcvt",\
		"strtod","strtol","strtoul","toascii","tolower","toupper"};	/*定义功能名称*/

	enum FUNC{
		ATOF,
		ATOI,
		ATOL,
		GCVT,
		STRTOD,
		STRTOL,
		STRTOUL,
		TOASCII,
		TOLOWER,
		TOUPPER
	}func_name;		/*注册功能函数名称*/
	 
	if(argc < 2)	/*是否有传入参数*/
	{
		printf("Usage : %s funcname\n",argv[0]);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG_TEST_0
	printf("sizeof(func) = %d\tchar_number = %d\n",sizeof(func),sizeof(func) / NAMELENGTH);
	printf("cmdlength = %d\n",strlen(argv[1]));
	printf("cmdstring : %s\n",argv[1]);
#endif
	int char_num = sizeof(func) / NAMELENGTH;	/*注册的功能个数*/

#if 0
	int i;
	for(i = 0; i < 9; i++)
	{
		printf("%s\n",func[i]);
	}
#else
	/*匹配功能名称*/
	int i ,ReDim = -1, ret;
	for(i = 0; i<char_num; i++)
	{
		if(ret =(!strncasecmp(func[i], argv[1],strlen(func[i]))))
		{
			ReDim = i;
			printf("Got an OK param : ReMin = %d\n",ReDim);
		}
	}

	/*未匹配成功，退出*/
	if(ReDim < 0 || ReDim >= char_num || ReDim == -1)
	{
		puts("funcname :");
		for(i = 0; i < char_num; i++)
		{
			printf("%d.%s  ",i,func[i]);
		}
		puts("");
		exit(EXIT_FAILURE);
	}

	func_name = ReDim;
	switch(func_name)
	{

			/*double atof(const char *nptr);将字符串转换成双精度浮点型*/
		case ATOF:
			{
				char *a = "-100.356";
				char *b = "200E-3";
				char *d = "adf+123.456\0089";
				float c;
				c = atof(a) + atof(b);
				printf("%s + %s = %f\n",a,b,c);
				printf("%s atof :%f\n",d,atof(d));

				break;
			}
		
			/*int atoi(const char *nptr);将字符串转换成整型*/
		case ATOI:
			{
				char *a = "-145.45";
				char *b = "  100\0099df";
				printf("a = %d\tb = %d\n",atoi(a),atoi(b));

				break;
			}

			/*long atol(const char *nptr);将字符串转换成长整型数*/
		case ATOL:
			{
				char *a = "-1425.89";
				char *b = "  123dfg";
				printf("a = %ld\tb = %ld\n",atol(a),atol(b));

				break;
			}

			/*char *gcvt(double number, size_t ndigit, char *buf);将浮点型数转化成字符串*/
		case GCVT:
			{
				double a = 123.45;
				double b = -1234.56;
				int sig = 6;
				char ptr[20];	/*第三个参数要指定大小，以免出现段错误*/

				/*通过命令行第三个参数设定存储的有效数字位数*/
				if(argc == 3)
				{
					sig = atoi(argv[2]);
					printf("设定存储的有效数字位数为：%d\n",sig);
				}
				else
				{
					printf("默认存储的有效数字位数为：%d\n",sig);
				}

				printf("OriVal a = %f\tb = %f\n",a,b);
				gcvt(a , sig, ptr);
				printf("a value %s\n",ptr);
				gcvt(b , sig, ptr);
				printf("b value %s\n",ptr);

				break;
			}

			/*double strtod(const char *nptr, char **endptr);将字符串转换成浮点数*/
		case STRTOD:
			{
				//char str[] = "a-123.456 P 56.789";	
				char str[] = "-123.45 88.9999";
				double D1,D2;
				char *sEnd;

				D1 = strtod(str, &sEnd);
				D2 = strtod(sEnd, NULL);
				printf("string :%s\n*sEnd :%s\n",str,sEnd);
				printf("D1 = %f\tD2 = %f\n",D1,D2);
				
				break;
			}
		
			/*long int strtol(const char *nptr, char **endptr, int base);将字符串转换成长整型
			*参数2：二级指针（指向一个字符串地址的指针），若参数
			*endptr 不为 NULL,则会将遇到不合条件而终止的 nptr 中的字符指
			*针由 endptr 返回。
			*base表示为要转换的进制，范围0-36；为0，转换成十进制，若遇到0x，转换成16进制；
			*/
		case STRTOL:
			{
				char a[] = "1000000000";
				char b[] = "1111111111";
				char c[] = "ffff";
				int base = 0;

				base = 10;
				printf("str:%s\t-(%02d)-> %ld\n",a,base,strtol(a, NULL, base));
				base = 2;
				printf("str:%s\t-(%02d)-> %ld\n",a,base,strtol(a, NULL, base));
				base = 10;
				printf("str:%s\t-(%02d)-> %ld\n",b,base,strtol(b, NULL, base));
				base = 2;
				printf("str:%s\t-(%02d)-> %ld\n",b,base,strtol(b, NULL, base));
				base = 16;
				printf("str:%s\t-(%02d)-> %ld\n",c,base,strtol(c, NULL, base));

				break;

			}

			/*unsigned long int strtoul(const char *nptr, char **endptr, int base); 将字符串转换成无符号长整形*/
			/*一始 strtoul（）会扫描参数
			  *nptr 字符串，跳过前面的空格字符串，直到遇上数字或正负符号才
			  *开始做转换，再遇到非数字或字符串结束时（’\0’）结束转换，并
			  *将结果返回。
			 */
		case STRTOUL:
			{	
				char a[] = " 1233333    0x555555";
				char *b;
				int base = 0;
				
				/*通过命令行第三个参数，设定要转换的进制*/
				if(argc == 3)
				{
					base = atoi(argv[2]);
					printf("设定要转换的进制为：%d\n",base);
				}
				else
				{
					printf("默认要转换的进制为：%d\n",base);
				}
				printf("str:%s\t-(%d)->  %ld\n",a,base,strtoul(a, &b, base));
				printf("str:%s\t\t-(%d)->  %ld\n",b,base,strtoul(b, NULL,base));

				break;
			}

			/*int toascii(int c);将整型数转换成合法的ASCII码字符*/
		case TOASCII:
			{
				int a = 217;
				char b;
				printf("before toascii():a value = %d(%c)\n",a,a);
				b = toascii(a);
				printf("after toascii():a value = %d(%c)\n",b,b);
				
				break;
			}
	
			/*int tolower(int c);将大写字母转化成小写字母*/
		case TOLOWER:
			{				
				char a[] = "ADCD##//efghijk12/*-0$%^。A";
				int i;

				printf("before tolower(): %s\n",a);
#if (0)
				for(i = 0; i < (sizeof(a) - 1); i++)
					a[i] = tolower(a[i]);
#else
				for(i = 0; i < strlen(a); i++)
					a[i] = tolower(a[i]);
#endif
				printf("ofter tolower(): %s\n",a);

				break;
			}

			/*int toupper(int c);将小写字母转化成大写字母*/
		case TOUPPER:
			{
				char a[] = "ADCD##//efghijk12/*-0$%^。";
				int i;

				printf("before toupper(): %s\n",a);
				for(i = 0; a[i] != 0; i++)
					a[i] = toupper(a[i]);
				printf("ofter toupper(): %s\n",a);

				break;
			}


			/*没有此功能*/
		default:
			puts("No such function !");
			exit(EXIT_FAILURE);
	}
#endif


	return 0;
}
#endif
