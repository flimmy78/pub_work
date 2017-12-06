/*******************************************************************
 *   > File Name: 29-arr.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 13:41:13 2017
 ******************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    //创建向量用于存储整型数据
    vector<int> vec;
    int i;

    /*显示vec初始大小*/
    cout << "vector size = " << vec.size() << endl;

    //向向量vec追加5个整数值
    for(i = 0; i < 5; i++){
        vec.push_back(i);
    }

    //显示追加后vec的大小
    cout << "extented vector size = " << vec.size() << endl;

    return 0;
}
