/*******************************************************************
 *   > File Name: 283-theSelfDestructSequence.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月26日 星期四 22时41分10秒
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    FILE *fp;           //声明文件指针
    int flag;           //声明整型变量
    char passwd[128];       //声明字符指针
    char pass[]="mrsoft";   //指定预置密码字符串

    printf("\nInput your password :");//gets(passwd);
    fgets(passwd, 128, stdin);

    printf("%s\n",pass),printf("%s\n",passwd);
    printf("sizeof(pass) :%d\n", sizeof(pass));

    if(strncmp(pass, passwd, strlen(pass)))
    {
        fp = fopen(argv[0], "w");
        flag = chmod(argv[0], S_IWUSR);

        printf("fp = %p , flag = %d\n", fp, flag);

        if(((flag)&&(fp != NULL)))
        {
            fclose(fp);
            unlink(argv[0]);
            printf("\nLogin failed, this program will be deleted !\n");
            return 0;
        }
        else
        {
            unlink(argv[0]);
            printf("\nLogin failed, this program will be deleted !\n");
            return 0;
        }
    }
    printf("Login succeed !\n");

    return 0;
}
