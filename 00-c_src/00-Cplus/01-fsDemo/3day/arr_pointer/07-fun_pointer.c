/*******************************************************************
 *   > File Name: 07-fun_pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 14:33:28 2017
 ******************************************************************/

#include <stdio.h>

/*声明四个函数*/
int fun1(int x, int y){
    return x+y;
}

int fun2(int x, int y){
    return x-y;
}

int fun3(int x, int y){
    return x*y;
}

int fun4(int x, int y){
    return x/y;
}

int main(int argc, char* argv[])
{
    int a = 5, b =3;

    /*声明一个函数指针数组，使用函数地址给数组初始化*/
    int (*arr[4])(int, int) = {fun1, fun2, fun3, fun4}; //arr为函数指针数组
    char str[] = "+-*/";
    int i;

    for(i = 0; i< 4; i++){
        printf("%d %c %d = %d\n", a, str[i], b, arr[i](a,b));
    }

    return 0;
}
