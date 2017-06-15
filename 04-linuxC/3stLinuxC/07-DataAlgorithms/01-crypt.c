/*******************************************************************
 *   > File Name: 01-crypt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jun 13 13:20:23 2017
 ******************************************************************/
#if (0)
char *crypt(const char *key, const char *salt);//将密码或者数据编码
//将使用 Data Encryption Standard (DES)演算法将参数 key
//所指的字符串加以编码，key 字符串长度仅取前 8 个字符，超过此返回值
//附加说明
//范例
//长度的字符没有意义。参数 salt 为两个字符组成的字符串，由 a-z、
//A-Z、0-9，“.”和“/”所组成，用来决定使用 4096 种不同内建表
//格的哪一个。函数执行成功后会返回指向编码过的字符串指针，参
//数 key 所指的字符串不会有所更动。编码过的字符串长度为 13 个
//字符，前两个字符为参数 salt 代表的字符串。
//返回一个指向以 NULL 结尾的密码字符串。
//使用 GCC 编译时需加-lcrypt
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define _XOPEN_SOUCE

int main(int argc, char* argv[])
{
    char passwd[13];
    char *key;
    char slat[2];

    key = getpass("Input First Password:");
    slat[0] = key[0];
    slat[1] = key[1];

    strcpy(passwd, crypt(key, slat));
    key = getpass("Input Second Password:");
    slat[0] = passwd[0];
    slat[1] = passwd[1];

    printf("After crypt(), 1st passwd :%s\n", passwd);
    printf("After crypt(), 2nd passwd :%s\n", crypt(key, slat));


    return 0;
}
