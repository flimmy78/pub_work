#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define N 11
typedef int datatype_node;
typedef struct node * datatype;
struct node{
    datatype_node data;
    struct node *next;
};
typedef struct hashtable{
    datatype *hp;   //指向hash表空间的指针
    int length;	    //hash表的空间长度
}hash_table,*hash_tp;
int p;

extern void init_hash(hash_tp *H,int m);
extern void  show(hash_tp h,int);
extern int fun(int);
extern hash_tp hash(int a[]);
extern struct node * hashsearch(hash_tp h,int key);
#endif
