#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef int datatype;
typedef struct seqlist{
    datatype data[SIZE];
    int last;//下标
}seq_list, *seq_plist;

seq_plist init_seqlist(void);
void init_seqlist_(seq_plist *L);
bool isempty_seqlist(seq_plist l);
bool isfull_seqlist(seq_plist l);
bool insert_seqlist(seq_plist l, datatype data);
bool del_seqlist(seq_plist l, datatype data);
void show_seqlist(seq_plist l);

#endif
