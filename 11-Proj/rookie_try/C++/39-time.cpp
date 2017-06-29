/*******************************************************************
 *   > File Name: 39-time.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:52:50 2017
 ******************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
    time_t now = time(0);   //基于当前系统的日期/时间

    char *dt = ctime(&now); //把now抓换成字符串形式

    cout << "本地日期和时间：" << dt << endl;

    //把now转换成tm结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC日期和时间：" << dt << endl;

    return 0;
}
