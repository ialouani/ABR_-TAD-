#include "./file.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct file{
  struct link* l;
};


struct file* file_empty(){
  struct link l2=lnk_init_empty();
  struct file* f=(struct file*)malloc(sizeof(struct file));
  f->l=(struct link*)malloc(sizeof(struct link));
  f->l->head=l2.head;
  f->l->tail=l2.tail;
  return f;
}

int file_is_empty(const struct file* f){
  struct link ll=lnk_init_empty();
  return f->l->head==ll.head && f->l->tail==ll.tail;
}

void file_push(struct file* q, void* z){
  struct lelement* add=(struct lelement*)malloc(sizeof(*add));
  add->data=z;add->next=NULL;
  lnk_add_head(q->l,add);
}

void file_pop(struct file* q){
  struct lelement* top=file_top(q);
  lnk_remove_tail(q->l);
  free(top);
}

void* file_top(struct file* f){
  struct lelement* tmp=f->l->head;
  struct link ll2=lnk_init_empty();
  while(tmp->next->data!=ll2.head->data){
    tmp=tmp->next;
  }
  return tmp;
}

void display(struct file* q){
  struct lelement* temp=q->l->head;
  while(*(int*)temp->data!=__INT_MAX__){
    printf("%d\t",*(int*)temp->data);
    temp=temp->next;
  }
  printf("\n");
  return;
}

void free2(struct file* q){
  struct lelement* temp=q->l->head;
  struct lelement* temp2;
  while(temp->next!=temp){
    temp2=temp->next;
    free(temp);
    temp=temp2;
  }
  free(q->l);
  free(q);
}

int size(struct file* q){
  struct lelement* tmp=q->l->head;
  struct link ll2=lnk_init_empty();
  int len=0;
  while(tmp->data!=ll2.head->data){
    len++;
    tmp=tmp->next;
  }
  return len;
}

void sort_file(struct file* q){
  struct lelement* tete=q->l->head;
  void* t[size(q)];
  for(int j=0;j<size(q);j++){
    t[j]=tete->data;
    tete=tete->next;
  }
  for(int k=size(q);k>=1;k--){
    for(int h=0;h<k-1;h++){
      if(*(int*)t[h]>*(int*)t[h+1]){
	void *ptr=t[h+1];
	t[h+1]=t[h];
	t[h]=ptr;
      }
    }
  }
  struct lelement* tete2=q->l->head;
  struct link lk=lnk_init_empty();
  int p=0;
  while(tete2->data!=lk.head->data){
    tete2->data=t[p];
    p++;
    tete2=tete2->next;
  }
}


  
