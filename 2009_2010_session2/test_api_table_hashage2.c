#include"./hashtable2.h"
#include"./lelement.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct hashtable{
  struct lelement** tab_listes;
  int length;
  hash_keys hash_ici;
  int(*test_equals__ici)(void*,void*);
};

int equals11(void* p, void* ppp){
  //specifique aux strings.
  return p==ppp;
}

int equals22(void* p, void* ppp){
  //specifique aux entiers.
  return *(int*)p-*(int*)ppp==0;
}

void display0(struct lelement* elmnt){
  if(elmnt->data==NULL) return;
  while(elmnt!=NULL){
    printf("%c\t",*(char*)(elmnt->data));
    elmnt=elmnt->next;
  }
  return;
}
void display00(struct lelement* elmnt){
  if(elmnt->data==NULL) return;
  while(elmnt!=NULL){
    printf("%d\t",*(int*)(elmnt->data));
    elmnt=elmnt->next;
  }
  return;
}

void display11(struct hashtable* ht){
  for(int i=0;i<ht->length;i++){
    display0(ht->tab_listes[i]);printf("\n");
  }
}

void display22(struct hashtable* ht){
  for(int i=0;i<ht->length;i++){
    display00(ht->tab_listes[i]);printf("\n");
  }
}

unsigned int hash(void* v, unsigned int n){
  return rand()%n;
}


static void test_all(){
  struct hashtable* ht=hashtable_init(5,hash,equals11);
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
  display11(ht);
  assert(hashtable_find(ht,a1)==1);
  assert(hashtable_find(ht,a2)==1);
  assert(hashtable_find(ht,a3)==1);
  assert(hashtable_find(ht,a4)==1);
  assert(hashtable_find(ht,a5)==1);
  assert(hashtable_find(ht,a6)==1);
  char* a7="a";
  assert(hashtable_find(ht,a7)==1);
  printf("%p\t%p\n",a1,a7);
  hashtable_free(ht);
  return;
}


static void test_all2(){
  struct hashtable* ht=hashtable_init(5,hash,equals22);
  int a1=1;
  int a2=2;
  int a3=3;
  int a4=4;
  int a5=5;
  int a6=6;
  hashtable_insert(ht,&a1);
  hashtable_insert(ht,&a2);
  hashtable_insert(ht,&a3);
  hashtable_insert(ht,&a4);
  hashtable_insert(ht,&a5);
  hashtable_insert(ht,&a6);
  display22(ht);
  assert(hashtable_find(ht,&a1)==1);
  assert(hashtable_find(ht,&a2)==1);
  assert(hashtable_find(ht,&a3)==1);
  assert(hashtable_find(ht,&a4)==1);
  assert(hashtable_find(ht,&a5)==1);
  assert(hashtable_find(ht,&a6)==1);
  int a7=1;
  assert(hashtable_find(ht,&a7)==1);
  printf("%p\t%p\n",&a1,&a7);
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
