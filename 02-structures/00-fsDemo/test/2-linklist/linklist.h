#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>

typedef int datatype;
typedef struct listnode
{
    datatype data;
    struct listnode *next;
}list_node, *list_pnode;

#endif
