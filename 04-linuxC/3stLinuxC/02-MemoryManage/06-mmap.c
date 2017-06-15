/*******************************************************************
 *   > File Name: 06-mmap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 14:42:28 2017
 ******************************************************************/
#if (0)
void *mmap(void *addr, size_t length, int port, int flags, int fd, off_t offset);
//mmap()用来将某个文件内容映射到内存中，对该内存区域的存取即是直接对该文件内容的读写。
//参数 addr 指向欲对应的内存起始地址，通常设为 NULL，代表让系统自动选定地址，对应成功后该地址会返回。
//参数 length 代表将文件中多大的部分对应到内存。
//参数 port 代表映射区域的保护方式，有下列组合：
    PROT_EXEC 映射区域可被执行
    PROT_READ 映射区域可被读取
    PROT_WRITE 映射区域可被写入
    PROT_NONE 映射区域不能存取
//参数 flags 会影响映射区域的各种特性：
MAP_FIXED //如果参数 start 所指的地址无法成功建立映射时，则放弃映射，不对地址做修正。通常不鼓励用此旗标。
MAP_SHARED// 对映射区域的写入数据会复制回文件内，而且返回值,允许其他映射该文件的进程共享。
MAP_PRIVATE// 对映射区域的写入操作会产生一个映射文件的复制，即私人的“写入时复制”（copy on write）
//对此区域作的任何修改都不会写回原来的文件内容。
MAP_ANONYMOUS// 建立匿名映射。此时会忽略参数 fd，不涉及文件，而且映射区域无法和其他进程共享。
MAP_DENYWRITE// 只允许对映射区域的写入操作，其他对文件直接写入的操作将会被拒绝。
MAP_LOCKED// 将映射区域锁定住，这表示该区域不会被置换（swap）。
//在调用 mmap()时必须要指定 MAP_SHARED 或 MAP_PRIVATE。
//参数 fd 为 open()返回的文件描述词，代表欲映射到内存的文件。参
//数 offset 为文件映射的偏移量，通常设置为 0，代表从文件最前方
//开始对应，offset 必须是分页大小的整数倍。
//若映射成功则返回映射区的内存起始地址，否则返回 MAP_FAILED
//（－1），错误原因存于 errno 中。
EBADF 参数 fd 不是有效的文件描述词
EACCES 存取权限有误。如果是 MAP_PRIVATE 情况下文件必须
//可读，使用 MAP_SHARED 则要有 PROT_WRITE 以及该文件要能写入。
EINVAL 参数 start、length 或 offset 有一个不合法。
EAGAIN 文件被锁住，或是有太多内存被锁住。
ENOMEM 内存不足。

int munmap(void *addr, size_t length);
//munmap()用来取消参数 start 所指的映射内存起始地址，参数 length
//则是欲取消的内存大小。当进程结束或利用 exec 相关函数来执行其
//他程序时，映射内存会自动解除，但关闭对应的文件描述词时不会
//解除映射。
//如果解除映射成功则返回 0，否则返回－1，错误原因存于 errno 中
//EINVAL 参数 start 或 length 不合法
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    int fd;
    void *start;
    struct stat sb;

    fd = open("/etc/passwd", O_RDONLY);
    fstat(fd, &sb);  /*get the information about a file*/
    /*将文件全部字节映射到内存上去（地址系统自动指定），可读*/
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED)
        return (-1);

    printf("%s", (char *)start);
    munmap(start, sb.st_size);/*解除映射*/

    return 0;
}
