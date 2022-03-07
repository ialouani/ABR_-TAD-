#include "./bintree.h"
#include<stdio.h>
#include<stdlib.h>

struct file{
  struct bintree* btr;
  struct file* next;
};

struct file* file_empty(){
  struct file* fl=(struct file*)malloc(sizeof(struct file));
  fl->btr=NULL;
  fl->next=NULL;
  return fl;
}

int file_is_empty(struct file* q){
  return q->btr==NULL;
}

void file_push(struct file* q, struct bintree* t){
  if(file_is_empty(q)){
    q->btr=t;
    q->next=NULL;
    return;
  }
  else{
    struct file* temp=q;
    while(temp->next!=NULL) temp=temp->next;
    struct file* fl2=(struct file*)malloc(sizeof(*fl2));
    fl2->btr=t;fl2->next=NULL;
    temp->next=fl2;
    return;
  }
}

void file_pop(struct file* fl){
  if(fl->next==NULL){
    fl->btr=NULL;
    return;}
  struct file* temp=fl;
  while(temp->next->next!=NULL) temp=temp->next;
  struct file* fl2=temp->next;
  temp->next=NULL;
  free(fl2);
  return;
}

struct bintree* file_top(struct file* fl){
  struct file* temp=fl;
  while(temp->next!=NULL) temp=temp->next;
  return temp->btr;
}
  
int count(struct bintree* bt){
  //parcours en largeur via la def. => programmer iterativement
  //le parcours d'arbre pour savoir le nombre de noeuds
  //=>utiliser l'imperatif avec une def. recursive
  //=>=>>>> R_I_I via unsing abstract structure of data:Queue. ()
  int cpt=0;
  struct file* fl=file_empty();
  file_push(fl,bt);
  while(!file_is_empty(fl)){
    struct bintree* bt2=file_top(fl);
    file_pop(fl);
    if(bt2!=NULL){
      cpt++;
      //printf("%d\t",cpt);
      file_push(fl,bt2->children[1]);
      file_push(fl,bt2->children[0]);
    }
  }
  free(fl);
  return cpt;
}
      

struct bintree* bintree_initialize(int x){
  struct bintree* bt=(struct bintree*)malloc(sizeof(struct bintree));
  bt->value=x;
  bt->children[0]=NULL;
  bt->children[1]=NULL;
}//initialisation en terme de NOUVELLE instance d'un arbre NON VIDE.

int bt_is_empty(const struct bintree* bt){
  return bt==NULL;
}

struct bintree * bt_left(const struct bintree* bt){
  if(!bt_is_empty(bt)) return bt->children[0];
  else{
    fprintf(stdout,"Impossible.\n");
    exit(1);
  }
}

struct bintree * bt_right(const struct bintree* bt){
  if(!bt_is_empty(bt)) return bt->children[1];
  else{
    fprintf(stdout,"Impossible.\n");
    exit(2);
  }
}

void display_bt(struct bintree* t){
  //une expression prefixe de retour..
  if(t==NULL) return;
  else{
    printf("%d\t",t->value);
    display_bt(t->children[0]);
    display_bt(t->children[1]);
    return;
  }
}

void link_to_do__left(struct bintree* n,struct bintree* n0){
  n->children[0]=n0;
}

void link_to_do__right(struct bintree* n,struct bintree* n1){
  n->children[1]=n1;
}

//un arbre binaire est soit nulle soit une racine avec 2 sentinelle (une feuille) soit un arbre ordinaire de profondeur>0 dont les feuilles sont marquees par des pointeurs vers des structures sentinelles.(l'arbre vide lui meme donc le pointage sera vers l'element NULL)

void free23(struct bintree* bt){
  if(bt==NULL) return;
  else{
    free23(bt->children[0]);
    free23(bt->children[1]);
    free(bt);
  }
}
