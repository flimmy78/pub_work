/*******************************************************************
 *   > File Name: 01-bubbleSort.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun Nov  5 22:34:30 2017
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

void show(int a[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    puts("");
}

void bubble_sort(int a[], int n){
    int i, j;
    int tmp;
    bool isSorted;

    for(i = 0; i < n - 1; i++){
        isSorted = true;
        for(j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                isSorted = false;
            }
        }
        if(isSorted)
            break;
        printf("Sorted %d:", i);
        show(a, n);
    }
}

int main(int argc, char* argv[])
{
    int a[8] =  {89,38,11,78,96,44,19,25};

    show(a, 8);

    bubble_sort(a, 8);

    show(a, 8);

    return 0;
}
