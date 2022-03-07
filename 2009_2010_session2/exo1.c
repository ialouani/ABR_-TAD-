#include "./exo1.h"
#include<stdio.h>
#include<stdlib.h>


int equals(void* p1, void* p2){
/*int cmp=*(int*)p1-*(int*)p2;
  if(cmp==0) return 1;*/
int cmp=p1-p2;
if(cmp==0) return 1;
return 0;
//return 0;
}

struct link lnk_init_empty(){
  struct link l;
  l.head=SENTINEL;
  return l;
}

void lnk_add_head(struct link* l, struct lelement* add){
  struct lelement* tmp=l->head;
  l->head=add;
  add->next=tmp;
}


int llm_find(struct lelement* l, void* v){
  return equals(l->data,v);
}

int main(){
struct link l1=lnk_init_empty();
int a1=1;int a2=2;int a3=1;int a4=a1;
struct lelement* add=(struct lelement*)malloc(sizeof(struct lelement));
add->data=&a1;
add->next=NULL;
struct lelement* add2=(struct lelement*)malloc(sizeof(struct lelement));
add2->data=&a2;
add2->next=NULL;
lnk_add_head(&l1,add2);
lnk_add_head(&l1,add);
printf("%d\n",llm_find(l1.head,&a1));
printf("%d\n",llm_find(l1.head,&a3));
printf("%d\n",llm_find(l1.head,&a4));
printf("%d\n",llm_find(l1.head,&a2));
printf("%d\n",llm_find(l1.head->next,&a1));
printf("%d\n",llm_find(l1.head->next,&a2));
free(l1.head->next);
free(l1.head);
puts("tout est OK.\n");
return 0;
}






