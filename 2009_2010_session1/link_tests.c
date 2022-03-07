#include "./link.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

static void test_all(){
  struct link l=lnk_init_empty();
  int a=1;int b=2;int c=3;
  struct lelement* add=(struct lelement*)malloc(sizeof(*add));
  add->data=&a;add->next=NULL;
  struct lelement* add2=(struct lelement*)malloc(sizeof(*add2));
  add2->data=&b;add2->next=NULL;
  struct lelement* add3=(struct lelement*)malloc(sizeof(*add3));
  add3->data=&c;add3->next=NULL;
  lnk_add_head(&l,add);
  lnk_add_head(&l,add2);
  lnk_add_head(&l,add3);
  assert(*(int*)l.head->data==3);
  assert(*(int*)l.head->next->data==2);
  assert(*(int*)l.head->next->next->data==1);
  assert(*(int*)l.head->next->next->next->data==__INT_MAX__);
  free(add);
  free(add2);
  free(add3);
  return;
}

int main(){
  test_all();
  puts("OK1/2..///\n");
  return 0;
}
