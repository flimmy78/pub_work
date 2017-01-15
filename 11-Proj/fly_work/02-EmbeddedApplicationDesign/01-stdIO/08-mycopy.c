/*******************************************************************
 *   > File Name: 08-mycopy.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 05:38:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>

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
        fprintf(stderr,"Fail to fopen %s : %s\n",argv[1],strerror(errno));
        return (-1);
    }

    if((fpd = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr,"Fail to fopen %s : %s\n",argv[2],strerror(errno));
        fclose(fps);
        return (-1);
    }

    while((n = fread(buf, 1, N, fps)) > 0)  //当读到的数目为0，表示文件读完
    {
#if (0)
        int i;
        for(i = 0; i < N; i++)
        {
            printf("%c",buf[i]);
        }
        puts("+");sleep(1);
#endif
        fwrite(buf, 1, n, fpd); //将缓冲buf中读到的数据写入流中
        //memset(buf,0,N);
    }

    fclose(fps);
    fclose(fpd);

    return 0;
}
