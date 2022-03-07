#ifndef FILE_H
#define FILE_H

#include "./link.h"

struct file;

struct file* file_empty();
int file_is_empty(const struct file*);
void file_push(struct file*, void*);
void file_pop(struct file*);
void* file_top(struct file*);
void display(struct file*);
void free2(struct file*);
void sort_file(struct file*);
int size(struct file*);

#endif
