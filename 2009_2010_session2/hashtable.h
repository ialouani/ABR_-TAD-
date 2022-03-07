#ifndef HASHTABLE_H
#define HASTABLE_H

struct hastable;

extern unsigned int hash ( void * , unsigned int n );
extern int equals ( void * , void * ) ;
struct hashtable * hashtable_init ( unsigned int n ) ;
int hashtable_find ( struct hashtable * , void *, int(*egaux)(void*, void*)) ;
void hashtable_insert ( struct hashtable * , void * ) ;
void hashtable_free ( struct hashtable * );
  
#endif /*HASTABLE_H*/
