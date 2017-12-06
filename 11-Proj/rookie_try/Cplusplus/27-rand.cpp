/*******************************************************************
 *   > File Name: 27-rand.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 10:13:02 2017
 ******************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    int i,j;

    //设置种子
    srand((unsigned)time(NULL));

    /*生成10个随机数*/
    for(i = 0; i < 10; i++){
        //生成实际的随机数
        j = rand();
        cout << "随机数 ：" << j << endl;
    }

    return 0;
}
