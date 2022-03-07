#include"./hashtable.h"
#include "./lelement.h"
#include<stdio.h>
#include<stdlib.h>
//#include<time.h>
//les foncitons rand sont dans <csdtlib> (C++).

//une table de hashage est un tableau de listes chainees.

struct hashtable{
  struct lelement** tab_listes;
  int length;
  //tableau de struct lelement*
  //i.e. tableau ou chaque element est de type struct lelement
  //i.e. une liste chainee.
};

unsigned int hash(void* v, unsigned int n){
  //retourne la cle que doit etre associee a la valeur encapsulee2 void* (v)###.
  //c'est un calcul fonction de l'adresse v suivant une plage de possibilitees
  //allant de 0 a n-1. la, pour runer les tests, on choisit une valeur aleatoire
  //de 0 a n-1 et ca tombe bien car deux valeurs differentes(pointeus)
  //peuvent etre hashees par le meme entier car rappel: C'EST PAS injectif du tt.
  
  
  //retourne la cle de l'identifiant *v dans une table de hashage
  //de len n indices de 0 à n-1
  //srand(time(NULL));
  return rand()%n;//nombre >=0 et <n. donc entre 0 et n-1 ; plages
  //dindices de la table de hashage.
}

int equals(void* v1, void* v2){
  return v1-v2==0;
}

struct hashtable* hashtable_init(unsigned int n){
  struct hashtable* ht=(struct hashtable*)malloc(sizeof(struct hashtable));
  //ht->tab_listes est un tableau de struct lelement*
  //donc un tableau de listes chainees.
  ht->tab_listes=(struct lelement**)malloc(sizeof(struct lelement*)*n);
  //allocation d'un tableau de n pointeurs
  //ou chaque pointeur est un tableau de void*.
  //ht->tab_listes[0] represente la 1ere liste chainee.
  //ht->tab_listes[n-1] represente lavant derniere listes chainee.
  ht->length=n;
  for(int i=0;i<n;i++){
    ht->tab_listes[i]=llm_init_empty();
  }
  return ht;
}

void hashtable_insert(struct hashtable* ht, void* pr){
  int len_hashtable=ht->length;
  unsigned int cle=hash(pr,len_hashtable);
  struct lelement* tmp=ht->tab_listes[cle];
  struct lelement* add=(struct lelement*)malloc(sizeof(struct lelement));
  add->data=pr; add->next=NULL;
  //la liste chainee des elements void* identifies par la meme cle: cle.
  llm_add_head(tmp,add);
  return;
}
/*
int hashtable_find(struct hashtable* ht, void* pr){
  //retourne la cle de lelement via pr.
  for(int i=0;i<ht->length;i++){
    struct lelement* tmp=ht->tab_listes[i];//recupere la lc numero i.
    while(tmp->data!=NULL){//cellule non **vide**.
      if(tmp->data==pr) return i;
      tmp=tmp->next;
    }
  }
  }*/
//indique(CAR<<) la presence seulement de pr.(find/set__find --exemplES)

//on suppose qu'il existe et on veut recuperer la cle bien sur.
//length est variable ce qui rend la table de hashage pas injective
//en terme des elements et des cles des champs de type void*.



int hashtable_find(struct hashtable* ht, void* pr,int(*egaux)(void*,void*)){
  for(int i=0;i<ht->length;i++){
    if(llm_find(ht->tab_listes[i],pr,egaux)) return 1;
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
    if(tmp->data==NULL){//debut par une encapsulation d'un pointeur NULL
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
  




			
