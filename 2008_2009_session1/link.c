#include"./link.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

static const int number=__INT_MAX__;
static const struct lelement sentinel={(void*)(&number),(struct lelement*)(&(sentinel))};
#define SENTINEL ((struct lelement*)&sentinel)

struct link lnk_init_empty(){
  struct link l;
  l.head=SENTINEL;
  l.tail=SENTINEL;
  return l;
}

void lnk_add_head(struct link* l, struct lelement* add){
  struct lelement* tmp=l->head;
  l->head=add;
  add->next=tmp;
}

void lnk_remove_head(struct link* l){
  struct lelement* tete=l->head;
  l->head=l->head->next;
  tete->next=NULL;
  //free(tete);
}

void lnk_add_tail(struct link* l, struct lelement* add){
  if(l->head==SENTINEL){
    lnk_add_head(l,add);return;
  }
  struct lelement* tete=l->head;
  while(tete->next!=SENTINEL){
    tete=tete->next;
  }
  tete->next=add;
  add->next=SENTINEL;
  l->tail=add;
}

void lnk_remove_tail(struct link* l){
  if(l->head->next==SENTINEL){
    lnk_remove_head(l);
    return;
  }
  struct lelement* temp=l->head;
  struct lelement* temp2;
  while(temp->next!=SENTINEL){
    temp2=temp;
    temp=temp->next;
  }
  temp2->next=SENTINEL;
  l->tail=temp2;
  //free(temp);
}

void lnk_add_after(struct link* l, struct lelement* after,struct lelement* add){
  if(after->next==SENTINEL){
    lnk_add_tail(l,add);
  }
  struct lelement* temp=l->head;
  while(temp!=after){
    temp=temp->next;
  }
  struct lelement* temp2=temp->next;
  temp->next=add;
  add->next=temp2;
}

void lnk_remove_after(struct link* l, struct lelement* after){
  struct lelement* temp=l->head;
  while(temp!=after){
    temp=temp->next;
  }
  if(after->next->next==SENTINEL){
    lnk_remove_tail(l);return;
  }
  struct lelement* temp3=temp->next;
  struct lelement* temp2=temp->next->next;
  temp->next=temp2;
  temp3->next=NULL;
  free(temp3);
  
}
  

  
  



  

  
