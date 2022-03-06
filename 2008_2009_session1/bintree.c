#include "./bintree.h"
#include<stdio.h>
#include<stdlib.h>

struct bintree* bintree_empty(void){
  return NULL;
}

int bt_is_empty(const struct bintree* bt){
  return bt==NULL;
}

struct bintree * bt_left(const struct bintree* bt){
  if(!bt_is_empty(bt)) return bt->children[0];
  else{
    fprintf("Impossible.\n");
    exit(1);
  }
}

struct bintree * bt_right(const struct bintree* bt){
  if(!bt_is_empty(bt)) return bt->children[1];
  else{
    fprintf("Impossible.\n");
    exit(2);
  }
}

//un arbre binaire est soit nulle soit une racine avec 2 sentinelle (une feuille) soit un arbre ordinaire de profondeur>0 dont les feuilles sont marquees par des pointeurs vers des structures sentinelles.(l'arbre vide lui meme donc le pointage sera vers l'element NULL)
