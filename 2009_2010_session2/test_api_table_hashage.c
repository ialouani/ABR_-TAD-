#include"./hashtable.h"
#include"./lelement.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int(*test_egalite)(void*,void*);
//je definis un type qui est le pointeur generique de fonction: test_egalite
//la declaration par affectation d'une fonction dans une variable de ce type
//se fera par exemple via: test_egalite equals3=equals4.


int equals4(void* p, void* ppp){
  //specifique aux strings.
  return p==ppp;
}

int equals5(void* p, void* ppp){
  //specifique aux entiers.
  return *(int*)p-*(int*)ppp==0;
}

struct hashtable{
  struct lelement** tab_listes;
  int length;
};

void display0(struct lelement* elmnt){
  if(elmnt->data==NULL) return;
  while(elmnt!=NULL){
    printf("%c\t",*(char*)(elmnt->data));
    elmnt=elmnt->next;
  }
  //printf("\n");
  return;
}
void display00(struct lelement* elmnt){
  if(elmnt->data==NULL) return;
  while(elmnt!=NULL){
    printf("%d\t",*(int*)(elmnt->data));
    elmnt=elmnt->next;
  }
  //printf("\n");
  return;
}

void display(struct hashtable* ht){
  for(int i=0;i<ht->length;i++){
    display0(ht->tab_listes[i]);printf("\n");
  }
}

void display2(struct hashtable* ht){
  for(int i=0;i<ht->length;i++){
    display00(ht->tab_listes[i]);printf("\n");
  }
}

static void test_all(){
  test_egalite equals3;
  equals3=equals4;
  struct hashtable* ht=hashtable_init(5);//table de hashage dont la longueur
//est 10, c'est une table dont les elements sont des listes chainees
//de type struct lelement* et dont l'index dans la table definit la cle
//associee a chaque capsule soit capsule->data appartenant a la liste chainee
//dans ladite position(index).
  char* a1="a";
  char* a2="b";
  char* a3="c";
  char* a4="d";
  char* a5="e";
  char* a6="f";
  hashtable_insert(ht,a1);
  hashtable_insert(ht,a2);
  hashtable_insert(ht,a3);
  hashtable_insert(ht,a4);
  hashtable_insert(ht,a5);
  hashtable_insert(ht,a6);
  display(ht);
  assert(hashtable_find(ht,a1,equals3)==1);
  assert(hashtable_find(ht,a2,equals3)==1);
  assert(hashtable_find(ht,a3,equals3)==1);
  assert(hashtable_find(ht,a4,equals3)==1);
  assert(hashtable_find(ht,a5,equals3)==1);
  assert(hashtable_find(ht,a6,equals3)==1);
  char* a7="a";
  assert(hashtable_find(ht,a7,equals3)==1);
  printf("%p\t%p\n",a1,a7);//memes adresses car tire le contenu depuis
  //le deferencement d'une statique des letape des .o differemment2.//
  hashtable_free(ht);
  return;
}
//reste find et free(via valgrind donc ajout seulement sur celui la en terme
//de TESTS).


static void test_all2(){
  test_egalite equals3;
  equals3=equals5;
  struct hashtable* ht=hashtable_init(5);//table de hashage dont la longueur
//est 10, c'est une table dont les elements sont des listes chainees
//de type struct lelement* et dont l'index dans la table definit la cle
//associee a chaque capsule soit capsule->data appartenant a la liste chainee
//dans ladite position(index).
  int a1=1;
  int a2=2;
  int a3=3;
  int a4=4;
  int a5=5;
  int a6=6;//oudes chars ca change pas grande chose.
  hashtable_insert(ht,&a1);
  hashtable_insert(ht,&a2);
  hashtable_insert(ht,&a3);
  hashtable_insert(ht,&a4);
  hashtable_insert(ht,&a5);
  hashtable_insert(ht,&a6);
  display2(ht);
  assert(hashtable_find(ht,&a1,equals3)==1);
  assert(hashtable_find(ht,&a2,equals3)==1);
  assert(hashtable_find(ht,&a3,equals3)==1);
  assert(hashtable_find(ht,&a4,equals3)==1);
  assert(hashtable_find(ht,&a5,equals3)==1);
  assert(hashtable_find(ht,&a6,equals3)==1);
  int a7=1;
  assert(hashtable_find(ht,&a7,equals3)==1);
  printf("%p\t%p\n",&a1,&a7);//memes adresses car tire le contenu depuis
  //le deferencement d'une statique des letape des .o differemment2.//
  hashtable_free(ht);
  return;
}

int main(int argc, char** argv){
  srand(atoi(argv[1]));
  test_all();
  test_all2();
  puts("TOUT EST OK.\n");
  return 0;
}
