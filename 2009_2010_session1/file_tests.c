#include "./file.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct file{
  struct link* l;
};

static void test_all(){
  struct file* q=file_empty();
  assert(file_is_empty(q));
  int a=1;int b=2;int c=3;int d=4;
  file_push(q,&a);
  file_push(q,&b);
  file_push(q,&c);
  file_push(q,&d);
  display(q);
  assert(!file_is_empty(q));
  assert(q->l->head->data==&d);
  display(q);
  assert(q->l->head->next->next->next->data==&a);
  assert(((struct lelement*)file_top(q))->data==&a);
  display(q);
  assert(size(q)==4);
  sort_file(q);
  display(q);
  free2(q);
  struct file* q2=file_empty();
  assert(file_is_empty(q2));
  int a2=1;int b2=2;int c2=3;int d2=4;
  file_push(q2,&a2);
  file_push(q2,&b2);
  file_push(q2,&c2);
  file_push(q2,&d2);
  file_pop(q2);
  assert(size(q2)==3);
  display(q2);
  file_pop(q2);file_pop(q2);
  assert(size(q2)==1);
  display(q2);
  file_pop(q2);
  assert(size(q2)==0);
  free2(q2);
  return;
}



int main(){
  test_all();
  puts("tout est OK.\n");
  return 0;

}
