/*******************************************************************
 *   > File Name: 04-getopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 04:59:12 PM CST
 ******************************************************************/
#if (0)
int getopt(int argc, char * const argv[],
        const char *optstring);/*分析命令行参数*/
//getopt（）用来分析命令行参数。参数 argc 和 argv 是由 main()传递
//的参数个数和内容。参数 optstring 则代表欲处理的选项字符串。此
//函数会返回在 argv 中下一个的选项字母，此字母会对应参数
//optstring 中的字母。如果选项字符串里的字母后接着冒号“： ” ，则
//表示还有相关的参数，全域变量 optarg 即会指向此额外参数。
//如果 getopt（）找不到符合的参数则会印出错信息，并将全域变量
//optopt 设为“？”字符，如果不希望 getopt（）印出错信息，则只
//要将全域变量 opterr 设为 0 即可。
//如果找到符合的参数则返回此参数字母，如果参数不包含在参数
//optstring 的选项字母则返回“？”字符，分析结束则返回-1。
#endif


#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int ch;
    
    opterr = 0;
    while((ch = getopt(argc, argv, "a:bcde")) != -1){
        switch(ch){
            case 'a':
                printf("Option a:%s\n",optarg);
                break;
            case 'b':
                printf("Option b:b\n");
                break;
            default:
                printf("Other option :%c\n",ch);
        }
    }

    printf("optopt + %c\n",optopt);

    return 0;
}
