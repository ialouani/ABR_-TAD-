#ifndef LELEMENT_H
#define LELEMENT_H

struct lelement{
  void* data;
  struct lelement* next;
};

struct lelement *llm_init_empty(void);
struct lelement *llm_add_head(struct lelement*, struct lelement*);
int llm_is_empty(struct lelement*);
int llm_find (struct lelement * l , void * v,int(*egaux)(void*,void*));

#endif /*LELEMENT_H*/
