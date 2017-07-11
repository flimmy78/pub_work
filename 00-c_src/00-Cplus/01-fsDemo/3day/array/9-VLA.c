/*******************************************************************
 *   > File Name: 9-VLA.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 10:51:33 PM CST
 ******************************************************************/

#include <stdio.h>

/*说明：
 *（1）.变长数组不能初始化；
 *（2）.变长数组必须是自动存储类型；
 *（3）.定义边长数组时，变量的值要确定却大于零
 * */

int main(int argc, char* argv[])
{
    int n, i;
    //n = 5;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i< n; i++){
        a[i] = i+1;
    }
    for(i = 0; i< n; i++){
        printf("%d\t", a[i]);
    }
    puts("");

    return 0;
}
