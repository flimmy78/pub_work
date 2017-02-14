/*************************************************************************/
//   File Name: json_string.c
//   Author: lpf
//   Created Time: 2015年03月17日 星期二 17时01分10秒
/************************************************************************/
	
#include <stdio.h>
#include </usr/local/include/json/json.h>
int main()
{
	char *recv_string = "{ \"sno\": 1001, \"name\": \"zhangsan\", \"score\": 97.800003 }";
	printf("%s\n",recv_string);
	
	//struct json_object *object,*fat,*json_sno,*json_name,*json_score;
	struct json_object *fat,*json_sno,*json_name,*json_score;
	int sno;
	char *name;
	float  score;
	//int num;
	
	/*将符合json格式的字符串构造为一个json对象，构造的json对象默认引用计数为1，同样需要在
     * 使用完成后对该对象调用一次json_object_put*/
	fat = json_tokener_parse(recv_string);
	//fat = json_object_array_get_idex(object,0);
	//fat = json_object_from_file(recv_string);
    /*从jso（fat）中获取键值为key的子对象。错误判断同样应该用is_error(jso)宏*/
	json_sno = json_object_object_get(fat,"sno");
	json_name= json_object_object_get(fat,"name");
	json_score = json_object_object_get(fat,"score");
	
    /*获取json对象的实际数据内容*/
	sno = json_object_get_int(json_sno);
	name = (char*)json_object_get_string(json_name);
	score = (float)json_object_get_double(json_score);
	
	printf("%d\t%s\t%f\n",sno,name,score);
	return 0;
}
