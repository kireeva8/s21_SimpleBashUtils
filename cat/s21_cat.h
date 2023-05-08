#ifndef S21_CAT_H
#define S21_CAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int n;
  int b;
  int s;
  int e;
  int t;
  int v;
  int file;
} CatFlags;

void print_file(FILE *fp, CatFlags *flags);
void parse_flags(char **argv, CatFlags *flags, int i);

#endif
