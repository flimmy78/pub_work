#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h> 
#include <string.h> 
 
//#include "json.h"
#include "/usr/local/include/json/json.h"
 
int main( int argc, char **argv) 
{ 
  struct json_tokener *tok; 
  struct json_object *my_string, *my_int, *my_object, *my_array; 
  struct json_object *new_obj; 
  int i; 
 
  my_string = json_object_new_string("\t"); 
/*输出  my_string=   */ 
  printf("my_string=%s\n", json_object_get_string(my_string)); 
/*转换json 格式字符串  输出my_string.to_string()="\t"*/ 
printf("my_string.to_string()=%s\n", json_object_to_json_string(my_string));   
/*释放资源*/ 
  json_object_put(my_string); 
 
  my_string = json_object_new_string("\\"); 
  printf("my_string=%s\n", json_object_get_string(my_string)); 
  printf("my_string.to_string()=%s\n", json_object_to_json_string(my_string)); 
json_object_put(my_string); 
my_string = json_object_new_string("foo"); 
printf("my_string=%s\n", json_object_get_string(my_string)); 
printf("my_string.to_string()=%s\n", json_object_to_json_string(my_string)); 
my_int = json_object_new_int(9); 
printf("my_int=%d\n", json_object_get_int(my_int)); 
printf("my_int.to_string()=%s\n", json_object_to_json_string(my_int)); 
/*创建个空json 对象值数组类型*/ 
my_array = json_object_new_array(); 
/*添加json 值类型到数组中*/ 
json_object_array_add(my_array, json_object_new_int(1)); 
json_object_array_add(my_array, json_object_new_int(2)); 
json_object_array_add(my_array, json_object_new_int(3)); 
json_object_array_put_idx(my_array, 4, json_object_new_int(5)); 
printf("my_array=\n"); 
for(i=0; i < json_object_array_length(my_array); i++) { 
   struct json_object *obj = json_object_array_get_idx(my_array, i); 
   printf("\t[%d]=%s\n", i, json_object_to_json_string(obj)); 
} 
printf("my_array.to_string()=%s\n", json_object_to_json_string(my_array));        
my_object = json_object_new_object(); 
/*添加json 名称和值到json 对象集合中*/ 
json_object_object_add(my_object, "abc", json_object_new_int(12)); 
json_object_object_add(my_object, "foo", json_object_new_string("bar")); 
json_object_object_add(my_object, "bool0", json_object_new_boolean(0)); 
json_object_object_add(my_object, "bool1", json_object_new_boolean(1)); 
json_object_object_add(my_object, "baz", json_object_new_string("bang")); 
/*同样的key 添加会替换掉*/ 
json_object_object_add(my_object, "baz", json_object_new_string("fark")); 
json_object_object_del(my_object, "baz"); 
   
printf("my_object=\n"); 
/*遍历json 对象集合*/ 
json_object_object_foreach(my_object, key, val) { 
   printf("\t%s: %s\n", key, json_object_to_json_string(val)); 
} 
printf("my_object.to_string()=%s\n", json_object_to_json_string(my_object)); 
/*对些不规则的串做了些解析测试*/ 
new_obj = json_tokener_parse("\"\003\""); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("/* hello */\"foo\""); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("// hello\n\"foo\""); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("\"\\u0041\\u0042\\u0043\""); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("null"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("True"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("12"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("12.3"); 
/*得到json double 类型 */
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("[\"\\n\"]"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("[\"\\nabc\\n\"]"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
json_object_put(new_obj); 
new_obj = json_tokener_parse("[null]"); 
printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
 json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("[]"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("[false]"); 
    printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("[\"abc\",null,\"def\",12]"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("{}"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("{ \"foo\": \"bar\" }"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("{ \"foo\": \"bar\", \"baz\": null, \"bool0\": true }"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("{ \"foo\": [null, \"foo\"] }"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
    json_object_put(new_obj); 
 
  new_obj  =  json_tokener_parse("{ \"abc\":  12, \"foo\": \"bar\", \"bool0\":  false, \"bool1\": true,\"arr\": [ 1, 2, 3, null, 5 ] }"); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj); 
 
  new_obj = json_tokener_parse("{ foo }"); 
  if(is_error(new_obj)) printf("got error as expected\n"); 
 
  new_obj = json_tokener_parse("foo"); 
  if(is_error(new_obj)) printf("got error as expected\n"); 
 
  new_obj = json_tokener_parse("{ \"foo"); 
  if(is_error(new_obj)) printf("got error as expected\n"); 
   /* test incremental parsing */ 
  tok = json_tokener_new(); 
    new_obj = json_tokener_parse_ex(tok, "{ \"foo", 6); 
  if(is_error(new_obj)) printf("got error as expected\n"); 
  new_obj = json_tokener_parse_ex(tok, "\": {\"bar ", 8); 
  if(is_error(new_obj)) printf("got error as expected\n"); 
  new_obj = json_tokener_parse_ex(tok, "\":13}}", 6); 
  printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj)); 
  json_object_put(new_obj);     
  json_tokener_free(tok); 
 
  json_object_put(my_string); 
  json_object_put(my_int); 
  json_object_put(my_object); 
  json_object_put(my_array);   
/*如果前面没有添加到对象中，  必须显示释放， 
  如果添加到对象中，已经释放对象，则无需调用，  在这务必小心，否则很容易内存泄漏*/ 
 
  return 0; 
} 
