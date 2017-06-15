/*******************************************************************
 *   > File Name: 12-getpw.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 10:54:37 2017
 ******************************************************************/
#if (0)
int getpw(uid_t uid, char *buf);//取得指定用户的密码文件数据
//getpw（）会从/etc/passwd 中查找符合参数 uid 所指定的用户账号数
//据，找不到相关数据就返回-1。所返回的 buf 字符串格式如下：
//账号：密码：用户识别码（uid）：组识别码（gid）：全名：根目录：
//shell
//返回 0 表示成功，有错误发生时返回-1。
//1. getpw（）会有潜在的安全性问题，请尽量使用别的函数取代。
//2. 使用 shadow 的系统已把用户密码抽出/etc/passwd，因此使用
//getpw（）取得的密码将为“x”
#endif

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[])
{
    char buffer[80];
    getpw(0, buffer);
    printf("%s\n", buffer);

    return 0;
}
