#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_inputs(void)
{
	int length;
	char *method;
	char *inputstring;

	method = getenv("REQUEST_METHOD");	//将返回结果赋予指针

	if(method == NULL)
		return 1;	//找不到环境变量REQUEST_METHOD
	else
		printf("REQUEST_METHOD : %s \n",method);

	if(!strcmp(method,"POST"))		//POST方法
	{
		length = atoi(getenv("CONTENT_LENGTH"));	//结果是字符，需要转换
		if(length != 0)
		{
			inputstring = malloc(sizeof(char)*length + 1 );	//申请缓存，因为stdin是不带缓存
			fread(inputstring,sizeof(char),length,stdin);	//从标准输入读取一定数据
		}
	}
	else if(!strcmp(method,"GET"));
	{
		inputstring = getenv("QUERY_STRING");
		length = strlen(inputstring);
		printf("QUERY_STRING : %s \n",inputstring);
	}

	if(length == 0)
		return 0;
}

int main(void)
{
	int ret;

	ret = get_inputs();

	return 0;
}
