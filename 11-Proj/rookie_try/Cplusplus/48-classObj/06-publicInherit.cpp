/*******************************************************************
 *   > File Name: 06-publicInherit.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 21:13:14 2017
 ******************************************************************/
/*NOTE
 * public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中
 * 分别变成：public, protected, private
 * */
#include<iostream>
#include<assert.h>
using namespace std;

class A{
    public:
        int a;
        A(){
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun(){
            cout << a << endl;    //正确
            cout << a1 << endl;   //正确
            cout << a2 << endl;   //正确
            cout << a3 << endl;   //正确
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};
class B : public A{
    public:
        int a;
        B(int i){
            A();
            a = i;
        }
        void fun(){
            cout << a << endl;       //正确，public成员
            cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
            cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
            //cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
        }
};
int main(){
    B b(10);
    cout << b.a << endl;
    cout << b.a1 << endl;   //正确
    //cout << b.a2 << endl;   //错误，类外不能访问protected成员
    //cout << b.a3 << endl;   //错误，类外不能访问private成员
    //system("pause");
    return 0;
}
