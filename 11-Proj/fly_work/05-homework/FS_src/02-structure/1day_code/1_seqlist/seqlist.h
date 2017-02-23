#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8
typedef int datatype;
typedef struct seqlist{
    datatype data[SIZE];
    int last;
}seq_list,*seq_plist;

extern void init_seqlist(seq_plist *L);
extern bool insert_seqlist(seq_plist l,datatype data);
extern bool del_seqlist(seq_plist l,datatype data);
extern bool isfull_seqlist(seq_plist l);
extern bool isempty_seqlist(seq_plist l);
extern void show_seqlist(seq_plist l);

#endif
