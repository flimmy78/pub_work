/*******************************************************************
 *   > File Name: FuncPoint1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 11:10:30 AM CST
 ******************************************************************/
#if (0)
//实例中 populate_array 函数定义了三个参数，其中第三个参数是函数的
//指针，通过该函数来设置数组的值。
//实例中我们定义了回调函数 getNextRandomValue，它返回一个随机值，
//它作为一个函数指针传递给 populate_array 函数。
//populate_array 将调用 10 次回掉函数，并将回掉函数的返回值赋值给数组
#endif

#include <stdio.h>
#include <stdlib.h>

/*回调函数*/
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void)){
    size_t i = 0;
    for(i = 0; i <arraySize; i++){
        array[i] = getNextValue();
    }
}

/*获取随机数*/
int getNextRandomValue(void){
    return rand();
}

int main(int argc, char* argv[])
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    int i;

    for(i = 0; i < 10; i++){
        printf("%d ", myarray[i]);
    }
    printf("\n");

    return 0;
}
