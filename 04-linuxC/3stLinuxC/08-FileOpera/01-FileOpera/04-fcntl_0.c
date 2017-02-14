/*******************************************************************
 *   > File Name: 04-fcntl_0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 09:54:33 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/file.h>

#define TEST_FILE   "./file_lock.test"

#if (0)
int flock(int fd, int operation);/*锁定文件或解除锁定*/
//@return：成功返回0；出错返回-1，错误代码存在于errno。
//参数operation有下列四种情况：
//LOCK_SH 建立共享锁定。多个进程可同时对同一个文件作共享锁
//定。
//LOCK_EX 建立互斥锁定。一个文件同时只有一个互斥锁定。
//LOCK_UN 解除文件锁定状态。
//LOCK_NB 无法建立锁定时，此操作可不被阻断，马上返回进程。
//通常与LOCK_SH 或LOCK_EX 做OR（|）组合。
//单一文件无法同时建立共享锁定和互斥锁定，而当使用dup（）或
//fork（）时文件描述词不会继承此种锁定。
#endif

#define FILE_MODE       "a+"
#define OPERA_LOCK      LOCK_EX
#define OPERA_UNLOCK    LOCK_UN

int CIRCU_NUM = 64;

int main(int argc, char* argv[])
{
    FILE *fp = NULL;

    if((fp = fopen(TEST_FILE, FILE_MODE)) == NULL)/*打开文件*/
    {
        printf("file open error !\n");
        return (-1);
    }
    else
    {
        if(flock(fileno(fp), OPERA_LOCK) != 0)/*给文件上锁*/
        {
            printf("file lock by others\n");
        }
        else
        {
            printf("file locked sucess\n");
        }
    }
    while(1)
    {
        printf("%d--%c\n",CIRCU_NUM++,CIRCU_NUM);
        fprintf(fp,"%c\n", CIRCU_NUM);
        sleep(1);
        if(CIRCU_NUM == (64 + 10))
            break;
    }
    fclose(fp);
    flock(fileno(fp),OPERA_UNLOCK);/*解锁文件*/

    return 0;
}
