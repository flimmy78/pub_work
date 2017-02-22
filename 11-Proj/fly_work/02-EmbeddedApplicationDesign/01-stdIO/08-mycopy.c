/*******************************************************************
 *   > File Name: 08-mycopy.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 05:38:44 PM CST
 ******************************************************************/

/*头文件*/
#include <stdio.h>
#include <errno.h>
/*宏定义*/
#define N 64

int main(int argc, char* argv[])
{
    int n;
    char buf[N];
    FILE *fps, *fpd;

    if(argc < 3)
    {
        printf("Usage : %s <src_file> <dst_file>\n",argv[0]);
        return (-1);
    }

    if((fps = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr,"Fail to fopen %s : %s\n",argv[1],(char*)strerror(errno));
        return (-1);
    }

    if((fpd = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr,"Fail to fopen %s : %s\n",argv[2],(char*)strerror(errno));
        fclose(fps);
        return (-1);
    }

    while((n = fread(buf, 1, N, fps)) > 0)  //当读到的数目为0，表示文件读完
    {
#if (1)
        int i;
        for(i = 0; i < n; i++)
        {
            printf("%c",buf[i]);
        }
        sleep(1);
        //puts("+");sleep(1);
#endif
        fwrite(buf, 1, n, fpd); //将缓冲buf中读到的数据写入流中
        //memset(buf,0,N);
    }
    puts("\ncopy finished");

    fclose(fps);
    fclose(fpd);

    return 0;
}
