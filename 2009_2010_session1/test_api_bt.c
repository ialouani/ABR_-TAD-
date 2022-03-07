#include "bintree.h"
#include<stdio.h>
#include<stdlib.h>

static void test_all(){
  struct bintree* bt1=bintree_initialize(4);
  /*display_bt(bt1);
    printf("\n\n");*/
  struct bintree* bt2=bintree_initialize(5);
  /*display_bt(bt2);
    printf("\n\n");*/
  struct bintree* bt_join1=bintree_initialize(2);
  /*display_bt(bt_join1);
    printf("\n\n");*/
  link_to_do__left(bt_join1,bt1);
  link_to_do__right(bt_join1,bt2);
  /*display_bt(bt_join1);
    printf("\n\n");*/
  struct bintree* bt11=bintree_initialize(6);
  struct bintree* bt22=bintree_initialize(7);
  struct bintree* bt_join11=bintree_initialize(3);
  link_to_do__left(bt_join11,bt11);
  link_to_do__right(bt_join11,bt22);
  struct bintree* bt_join=bintree_initialize(1);
  link_to_do__left(bt_join,bt_join1);
  link_to_do__right(bt_join,bt_join11);
  display_bt(bt_join);
  printf("\n\n");
  printf("Le nombre de noeuds est:%d\n",count(bt_join));
  free23(bt_join);
  return;
}



int main(){
  test_all();
  puts("TOUT EST OK.\n");
  return 0;
}
