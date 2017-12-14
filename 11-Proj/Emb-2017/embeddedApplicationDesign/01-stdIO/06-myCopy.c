/*******************************************************************
 *   > File Name: 06-mycopy.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 01 Sep 2017 11:04:46 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#define N   64

#define ENABLE  1
#define DISABLE 0
#define ERR_T_ONE   DISABLE
#define ERR_T_TWO   DISABLE

int main(int argc, char* argv[])
{
    char buf[N];
    FILE* fps, *fpd;
    int n;

    /*1.判断命令行参数*/
    if(argc < 3){
        fprintf(stderr, "Usage : %s <src_file> <dst_file>\n", argv[0]);
        return (-1);
    }

    /*2.打开源文件*/
    if((fps = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Fopen %s error : %s\n", argv[1], strerror(errno));
        return (-1);
    }

    /*3.打开目标文件*/
    if((fpd = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "Fopen %s error : %s\n", argv[2], strerror(errno));
        fclose(fps);
        return (-1);
    }

    /*4.复制文件*/
    while((n = fread(buf, 1, N, fps)) > 0){
#if (ERR_T_TWO == ENABLE)
        fwrite(buf, 1, N, fpd); //末尾会多写入11个填充字符
        bzero(buf, sizeof(buf));
#elif(ERR_T_ONE == ENABLE)
        fwrite(buf, 1, N, fpd); //多写入最后一次的前一次的最后11个字符
#else
        fwrite(buf, 1, n, fpd);
#endif
    }

    fclose(fps);
    fclose(fpd);

    return 0;
}
