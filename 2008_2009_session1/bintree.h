#ifndef BINTREE_H
#define BINTREE_H

struct bintree{
  int value;
  struct bintree* children[2];
};

struct bintree* bintree_empty(void);
int bt_is_empty(const struct bintree*);
struct bintree * bt_left(const struct bintree*);
struct bintree * bt_right(const struct bintree*);

#endif
