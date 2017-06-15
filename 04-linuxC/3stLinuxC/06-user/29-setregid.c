/*******************************************************************
 *   > File Name: 29-setregid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 18:02:57 2017
 ******************************************************************/
#if (0)
int setregid(gid_t rgid, gid_t egid);   //设置真实及有效的组识别码
//用来将参数 rgid 设为目前进程的真实组识别码，将参数
//egid 设置为目前进程的有效组识别码。如果参数 rgid 或 egid 值为-1，
//则对应的识别码不会改变。
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
