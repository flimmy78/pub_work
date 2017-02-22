#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef int datatype;
typedef struct doublenode{
    datatype data;
    struct list_head list;
}double_node,*double_pnode;

extern void init_doublelist(double_pnode *H);
extern void show_doublelist(double_pnode h);
extern void create_doublelist(double_pnode h);
extern void sort_doublelist(double_pnode h);
#endif
