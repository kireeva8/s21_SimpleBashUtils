#include "s21_cat.h"

int main(int argc, char **argv) {
  CatFlags flags = {0, 0, 0, 0, 0, 0, 1};
  if (argc == 1) {
    print_file(stdin, &flags);
  } else {
    for (int i = 1; i < argc; i++) {
      if (flags.file == 1) {
        parse_flags(argv, &flags, i);
      }
      if (flags.file == 0) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
          fprintf(stderr, "cat: %s: No such file or directory", argv[i]);
          continue;
        }
        print_file(fp, &flags);
        fclose(fp);
      }
    }
  }
  return 0;
}
void parse_flags(char **argv, CatFlags *flags, int i) {
  if (strcmp(argv[i], "--number-nonblank") == 0) {
    flags->b = 1;
  } else if (strcmp(argv[i], "--number") == 0) {
    flags->n = 1;
  } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
    flags->s = 1;
  } else if ((argv[i][0] != '-')) {
    flags->file = 0;
  } else {
    int j = 1;
    while (argv[i][j] != '\0') {
      if (argv[i][j] == 'b') {
        flags->b = 1;
      } else if (argv[i][j] == 'n') {
        flags->n = 1;
      } else if (argv[i][j] == 's') {
        flags->s = 1;
      } else if (argv[i][j] == 'e') {
        flags->e = 1;
        flags->v = 1;
      } else if (argv[i][j] == 'E') {
        flags->e = 1;
      } else if (argv[i][j] == 't') {
        flags->t = 1;
        flags->v = 1;
      } else if (argv[i][j] == 'T') {
        flags->e = 1;
      } else if (argv[i][j] == 'v') {
        flags->v = 1;
      } else {
        flags->file = 0;
      }
      j++;
    }
  }
}

void print_file(FILE *fp, CatFlags *flags) {
  char sym, prev = '\n';    // for iteration
  int temp = 0, count = 1;  // temp - count '\n'
  while ((sym = fgetc(fp)) != EOF) {
    if (flags->s && prev == '\n') {
      if (sym == '\n') {
        temp++;
      }
      if (sym != '\n') {
        temp = 0;
      }
    }
    if (sym == '\n' && (!flags->s || temp < 2)) {
      if (flags->n && prev == '\n' && !flags->b) {
        printf("%6d\t", count++);
      }
      if (flags->e) {
        printf("$");
      }
      printf("%c", sym);
    }
    if (sym != '\n') {
      if ((prev == '\n') && (flags->b || flags->n)) {
        printf("%6d\t", count++);
      }
      if (sym < 32 && sym != 9 && sym != 10 && flags->v) {
        printf("^%c", sym + 64);
      } else if (sym == 127 && flags->v) {
        printf("^%c", sym - 64);
      } else if (sym == '\t' && flags->t) {
        printf("^I");
      } else {
        printf("%c", sym);
      }
    }
    prev = sym;
  }
}
