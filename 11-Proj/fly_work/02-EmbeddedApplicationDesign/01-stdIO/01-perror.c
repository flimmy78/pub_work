/*******************************************************************
 *   > File Name: 01-perror.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 11:05:33 PM CST
 ******************************************************************/
#if (0)
FILE *fopen(const char *path, const char *mode);/*打开流*/
//mode:文件的打开方式：
//r或rb：
//r+或r+b：
//w或wb：
//w+或w+b：
//a或ab：
//a+或a+b
//return:成功返回指向FILE的指针，失败返回NULL
int fclose(FILE *fp);/*关闭流*/
void perror(const char *s);/*打印错误信息*/
#endif

#include <stdio.h>
#include <errno.h>
/*宏定义*/
#define FILEPATH "./1.txt"/*文件路径*/

int main(void)
{
    FILE* fp;   //定义流指针

    if((fp = fopen(FILEPATH,"r")) == NULL)/*打开文件流*/{
        perror("Fail to open");
        printf("Errno %d\n",errno);
        //return (-1);
    }else{
        printf("(%d) Open %s OK\n",__LINE__,FILEPATH);
        printf("FILE_POINTER is %p\n",fp);
    }

    if(fclose(fp) != 0){/*关闭文件流*//*此处，文件打开不正确，
                                        执行了无效的内存引用,回报段错误*/
        perror("fclose");
    }

    return 0;
}
