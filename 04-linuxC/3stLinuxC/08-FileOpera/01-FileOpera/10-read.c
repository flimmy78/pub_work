/*******************************************************************
 *   > File Name: 10-read.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 11:37:42 2017
 ******************************************************************/
#if (0)
ssize_t read(int fildes, void *buf, size_t nbyte);  //由已打开的文件读取数据
//把参数 fd 所指的文件传送 count 个字节到 buf 指针所指
//的内存中。若参数 count 为 0，则 read（）不会有作用并返回 0。返
//回值为实际读取到的字节数，如果返回 0，表示已到达文件尾或是
//无可读取的数据，此外文件读写位置会随读取到的字节移动。
//如果顺利 read（）会返回实际读到的字节数，最好能将返回值与参
//数 count 作比较，若返回的字节数比要求读取的字节数少，则有可
//能读到了文件尾、从管道（pipe）或终端机读取，或者是 read（）
//被信号中断了读取动作。当有错误发生时则返回-1，错误代码存入
//errno 中，而文件读写位置则无法预期。
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    return 0;
}
