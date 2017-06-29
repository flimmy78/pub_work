#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct listnode{
    datatype data;
    struct listnode *next;
}list_node,*list_pnode;

extern void init_linklist(list_pnode *H);
extern void insert_linklist(list_pnode p,list_pnode new);
extern void del_linklist(list_pnode p);
extern void create_linklist(list_pnode h);
extern void show_linklist(list_pnode h);
extern void sort_linklist(list_pnode h);
#endif
