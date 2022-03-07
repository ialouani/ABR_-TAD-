#include"./hashtable2.h"
#include "./lelement.h"
#include<stdio.h>
#include<stdlib.h>



struct hashtable{
  struct lelement** tab_listes;
  int length;
  hash_keys hash_ici;
  int(*test_equals__ici)(void*,void*);
};

/*
unsigned int hash(void* v, unsigned int n){
  return rand()%n;
}
*/
/*
int equals(void* v1, void* v2){
  return v1-v2==0;
}
*/
//c'etait pas necessaire des le debut de l'exo2 via debut tests celle ci..///

struct hashtable* hashtable_init(unsigned int n,hash_keys hashage,test_equals equals_ici){
  struct hashtable* ht=(struct hashtable*)malloc(sizeof(struct hashtable));
  ht->tab_listes=(struct lelement**)malloc(sizeof(struct lelement*)*n);
  ht->length=n;
  for(int i=0;i<n;i++){
    ht->tab_listes[i]=llm_init_empty();
  }
  ht->hash_ici=hashage;
  ht->test_equals__ici=equals_ici;
  return ht;
}

void hashtable_insert(struct hashtable* ht, void* pr){
  int len_hashtable=ht->length;
  unsigned int cle=ht->hash_ici(pr,len_hashtable);
  struct lelement* tmp=ht->tab_listes[cle];
  struct lelement* add=(struct lelement*)malloc(sizeof(struct lelement));
  add->data=pr; add->next=NULL;
  llm_add_head(tmp,add);
  return;
}



int hashtable_find(struct hashtable* ht, void* pr){
  for(int i=0;i<ht->length;i++){
    if(llm_find(ht->tab_listes[i],pr,ht->test_equals__ici)) return 1;
  }
  return 0;
}

void hashtable_free(struct hashtable* ht){
  for(int i=ht->length-1;i>=0;i--){
    struct lelement* tmp=ht->tab_listes[i];
    struct lelement* tmp3;
    if(tmp->next!=NULL){
      tmp3=tmp->next;
      if(tmp3->data==NULL) free(tmp);
    }
    if(tmp->data==NULL){
      free(tmp);
    }
    else{
      struct lelement* tmp2;
      while(tmp!=NULL){
	tmp2=tmp->next;
	free(tmp);
	tmp=tmp2;
      }
    }
  }
  free(ht->tab_listes);
  free(ht);
}
