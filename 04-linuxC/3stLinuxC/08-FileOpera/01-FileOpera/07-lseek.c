/*******************************************************************
 *   > File Name: 07-lseek.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 10:13:04 2017
 ******************************************************************/
#if (0)
off_t lseek(int fd, off_t offset, int whence);
//每一个已打开的文件都有一个读写位置，当打开文件时通常其读写
//位 置 是 指 向 文 件 开 头 ， 若 是 以 附 加 的 方 式 打 开 文 件 （ 如
//O_APPEND），则读写位置会指向文件尾。当 read（） 或 write（）
//时，读写位置会随之增加，lseek（）便是用来控制该文件的读写位
//置。参数 fildes 为已打开的文件描述词，参数 offset 为根据参数
//whence 来移动读写位置的位移数。参数 whence 为下列其中一种：
//SEEK_SET 参数 offset 即为新的读写位置。
//SEEK_CUR 以目前的读写位置往后增加 offset 个位移量。
//SEEK_END 将读写位置指向文件尾后再增加 offset 个位移量。
//当 whence 值为 SEEK_CUR 或 SEEK_END 时，参数 offet 允许负值
//的出现。
//下列是教特别的使用方式：
//1) 欲将读写位置移到文件开头时：lseek（int fildes,0,SEEK_SET）；
//2) 欲将读写位置移到文件尾时：lseek（int fildes，0,SEEK_END）；
//3) 想要取得目前文件位置时：lseek（int fildes，0,SEEK_CUR）；
//当调用成功时则返回目前的读写位置，也就是距离文件开头多少个
//字节。若有错误则返回-1，errno 会存放错误代码。
//Linux 系统不允许 lseek（）对 tty 装置作用，此项动作会令 lseek（）
//返回 ESPIPE
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
