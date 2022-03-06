#ifndef LINK_H
#define LINK_H

struct link {
  struct lelement *head;
  struct lelement *tail;
};

struct lelement {
  void* data;
  struct lelement *next;
};

struct link lnk_init_empty(void);

void lnk_add_head(struct link*, struct lelement*);
void lnk_remove_head(struct link*);
void lnk_add_tail(struct link*, struct lelement*);
void lnk_remove_tail(struct link*);


void lnk_add_after(struct link*, struct lelement*,struct lelement*);
void lnk_remove_after(struct link*, struct lelement*);

#endif 
