#include"./lelement.h"
#include<stdio.h>
#include<stdlib.h>


struct lelement* llm_init_empty(){
  struct lelement* elmnt=(struct lelement*)malloc(sizeof(*elmnt));
  elmnt->data=NULL;
  elmnt->next=NULL;
}

struct lelement* llm_add_head(struct lelement* lc, struct lelement* capsule){
  if(lc->data==NULL){
    lc->data=capsule->data;
    lc->next=NULL;
    free(capsule);
    return lc;}
  else{
  struct lelement* tmp=lc->next;
  lc->next=capsule;
  capsule->next=tmp;
  return lc;
}
}
int llm_is_empty(struct lelement* elmnt){
  return elmnt->data==NULL;
}

int equals2(void* pr1, void* pr2){
  return pr1-pr2==0;
}

int llm_find (struct lelement * l , void * v,int(*egaux)(void*,void*)){
  if(llm_is_empty(l)) return 0;
  while(l!=NULL){
    if(egaux(l->data,v)) return 1;
    l=l->next;
  }
  return 0;
}
