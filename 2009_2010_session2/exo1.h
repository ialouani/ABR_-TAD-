#ifndef __deux
#define __deux



struct link{
  struct lelement* head;
};

struct lelement{
  void* data;
  struct lelement* next;
};

static const int number=__INT_MAX__;
static const struct lelement sentinel={(void*)(&number),(struct lelement*)(&(sentinel))};
#define SENTINEL ((struct lelement*)&sentinel)



struct link lnk_init_empty();
void lnk_add_head(struct link*,struct lelement*);
void lnk_remove_head(struct link*);
int llm_find(struct lelement* l, void* v);

#endif
