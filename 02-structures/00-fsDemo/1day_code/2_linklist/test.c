/*
 2、用单向链表实现数据逆转，首先建立一个包含若干整数的单向链表，然后参考讲义的例子实现数据的逆转。（比如说把1，2，3，4，5逆转成5，4，3，2，1）
 */

#include "linklist.h"

int main(void)
{
    list_pnode h;

    init_linklist(&h);   //初始化空链表
    create_linklist(h);
    sort_linklist(h);   //对链表中的数据逆转

    return 0;
}
