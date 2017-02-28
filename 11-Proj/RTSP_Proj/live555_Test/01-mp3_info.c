/*******************************************************************
 *   > File Name: 01-mp3_info.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Feb 2017 05:00:48 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*帧头长4字节，对于固定位率的MP3文件，所有帧的帧头格式一样其数据结构如下*/
typedef FrameHeader {
    unsigned int sync: 11;                         //同步信息
    unsigned int version: 2;                       //版本
    unsigned int layer: 2;                                     //层
    unsigned int error protection: 1;                  // CRC校验
    unsigned int bitrate_index: 4;             //位率
    unsigned int sampling_frequency: 2;         //采样频率
    unsigned int padding: 1;                     //帧长调节
    unsigned int private: 1;                        //保留字
    unsigned int mode: 2;                          //声道模式
    unsigned int mode extension: 2;        //扩充模式
    unsigned int copyright: 1;                            // 版权
    unsigned int original: 1;                       //原版标志
    unsigned int emphasis: 2;                   //强调模式
}HEADER, *LPHEADER;


typedef struct _MP3_info{
    char HEAD[3];   /*存放“TAG”字符，表示ID3 V1.0标准，紧接其后的是歌曲信息。*/
    char NAME[30];  /*歌名*/
    char AUTHOR[30];/*作者*/
    char DVD[30];   /*专辑名*/
    char YEAR[4];   /*年份*/
    char REMARK[30];/*附注*/
    char CLASSES[1];/*MP3音乐类别，共147种*/
}MP3_info;

int main(int argc, char* argv[])
{
    MP3_info INFO;
    int fd;
    int retval;
    char buf[128] = {0};

    /*获取文件名*/
    if(argc < 2){
        printf("Usage :%s <MP3_filepath>\n",argv[0]);exit(1);
    }

    /*打开文件*/
    if((fd = open(argv[1], O_RDONLY)) < 0){
        fprintf(stderr,"open %s err :%s\n",argv[1], (char*)strerror(errno));exit(1);
    }

    /*定位文件*/
   if( (retval = lseek(fd, -128, SEEK_END)) < 0){
        perror("lseek error");exit(1);
   }

   if((retval = read(fd, buf, 128)) != 128){
        perror("read fd error");exit(1);
   }

    printf("buf:%s\n",buf);


    return 0;
}
