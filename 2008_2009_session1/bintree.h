#ifndef BINTREE_H
#define BINTREE_H

struct bintree{
  int value;
  struct bintree* children[2];
};

struct bintree* bintree_initialize(int);
int bt_is_empty(const struct bintree*);
struct bintree * bt_left(const struct bintree*);
struct bintree * bt_right(const struct bintree*);
void link_to_do__left(struct bintree* n,struct bintree* n0);
void link_to_do__right(struct bintree* n,struct bintree* n1);
void display_bt(struct bintree*);
void free23(struct bintree*);
int count(struct bintree*);

#endif
