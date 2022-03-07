#ifndef HASHTABLE_H
#define HASTABLE_H

struct hastable;
typedef unsigned int(*hash_keys)(void*,unsigned int);
typedef int(*test_equals)(void*,void*);
extern unsigned int hash ( void * , unsigned int n );
extern int equals ( void * , void * ) ;
struct hashtable* hashtable_init(unsigned int n,hash_keys hashage,test_equals equals_ici);
int hashtable_find ( struct hashtable * , void *) ;
void hashtable_insert ( struct hashtable * , void * ) ;
void hashtable_free ( struct hashtable * );
  
#endif /*HASTABLE_H*/
