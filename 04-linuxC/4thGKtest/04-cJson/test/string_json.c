/*************************************************************************/
//   File Name: string_json.c
//   Author: lpf
//   Created Time: 2015年03月17日 星期二 16时39分16秒
/************************************************************************/
	
#include <stdio.h>
#include "/usr/local/include/json/json.h"
int main()
{
	struct json_object *fat,*json_sno,*json_name,*json_score;

	int sno = 1001;
	char name[] = "zhangsan";
	float score = 97.8;

	//json打包
	//创建一个Json对象
	fat = json_object_new_object();
	
	//将不同类型数据转换成json对应的类型
	json_sno = json_object_new_int(sno);
	json_name= json_object_new_string(name);
	json_score = json_object_new_double(score);

	//将json类型的数据加入到json对象中
	json_object_object_add(fat,"sno",json_sno);
	json_object_object_add(fat,"name",json_name);
	json_object_object_add(fat,"score",json_score);

	//将JSON对象转换成字符串
	const char * json_string = json_object_to_json_string(fat);
	printf("%s\n",json_string);
	return 0;
}
