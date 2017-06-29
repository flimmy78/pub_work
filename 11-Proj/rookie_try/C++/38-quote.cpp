/*******************************************************************
 *   > File Name: 38-quote.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:40:07 2017
 ******************************************************************/

#include <iostream>
using namespace std;

double vals[] = {10.1 , 12.6, 33.1, 24.1, 50.0};

double& setValues(int i){
    return vals[i]; //返回第i个元素的引用
}

int main(void)
{
    cout << "改变前的值" << endl;
    
    for(int i = 0; i < 5; i++){
        cout << "val[" << i << "] = ";
        cout << vals[i] << endl;
    }

    setValues(1) = 20.23;   //改变第2个元素
    setValues(3) = 70.8;    //改变第4个元素

    cout << "改变后的值" << endl;
    for(int i = 0; i < 5; i++){
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }

    return 0;
}
