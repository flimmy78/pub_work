/*******************************************************************
 *   > File Name: leftdays.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 21 Mar 2017 09:46:30 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct tm today;
    time_t now;
    long days;

    time(&now);
    today = *localtime(&now);
    mktime(&today);

    if((today.tm_mon == 11) && (today.tm_mday == 20) && (today.tm_year == 90)){
        printf("<BR><FONT COLOR=\"#8080FF\">热烈庆祝澳门回到祖国怀抱！");
        printf("<\/FONT>/n");
    }else{
        days = 0;
        while((today.tm_mon != 11) || (today.tm_mday != 20) || (today.tm_year != 99)){
            days ++;
            today.tm_mday = today.tm_mday + 1;
            mktime(&today);
        }

        printf("<CENTER>");
        printf("<BR><FONT COLOR=\"#8080FF\" SIZE=\"+2\">");
        printf("<BR>距离中国人民共和国对");
        printf("<BR>澳门特别行政区恢复行使主权");
        printf("<BR>还有<B><FONT SIZE=\"+3\" COLOR=\"FF0000\">");
        printf("%i<\/FONT><\/B>天！",days);
        printf("<\/FONT>");
        printf("<\/CENTER>");
    }
    fflush(stdout);

    return 0;
}
