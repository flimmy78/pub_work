1.1-Linux系统调用和用户编程接口
1.1.1-系统调用：
1.进程控制
2.进程间通讯
3.文件系统控制
4.存储管理
5.网络管理
6.套接字管理
7.用户管理

1.1.2用户编程接口

1.2-Linux标准I/O概述
1.2.1-标准I/O的由来
1.2.2-流的含义
1.全缓冲
2.行缓冲
3.无缓冲

1.3-标准I/O编程
1.3.1-流的打开
#include <stdio.h>

FILE *fopen(const char *path, const char *mode);

FILE *fdopen(int fd, const char *mode);

FILE *freopen(const char *path, const char *mode, FILE *stream);

1.3.2-流的关闭
int fclose(FILE* stream);

1.3.3-错误的处理
void perror(const char* s);
char *strerror(int errnum);

1.3.4-流的读写
1.按字符（字节）输入/输出
int getc(FILE*stream);
int fgetc(FILE*stream);
int getchar(void);

int putc(int c,FILE*stream);
int fputc(int c,FILE*stream);
int putchar(int c);
2.按行输入\输出
char *gets(char*s);
char *fgets(char *s, int size, FILE*stream);

int puts(const char *s);
int fputs(const char *s,FILE *stream);

3.以指定大小为单位读写文件
size_t fread(void *ptr,size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr,size_t size, size_t nmemb, FILE*stream);

1.3.5-流的定位
int fseek(FILE*stream, long offset, int whence);

long ftell(FILE*stream);

1.3.69-格式化输入输出
int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);








