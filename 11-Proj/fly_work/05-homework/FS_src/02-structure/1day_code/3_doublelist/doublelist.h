#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct doublenode{
    datatype data;
    struct doublenode *next,*prev;
}double_node,*double_pnode;

extern void init_doublelist(double_pnode *H);
extern void insert_doublelist_next(double_pnode p,double_pnode new);
extern void insert_doublelist_prev(double_pnode p,double_pnode new);
extern void del_doublelist_next(double_pnode p);
extern void del_doublelist_prev(double_pnode p);
extern void del_doublelist_cur(double_pnode p);
extern void show_doublelist(double_pnode h);
extern void create_doublelist(double_pnode h);
extern void sort_doublelist(double_pnode h);
#endif
