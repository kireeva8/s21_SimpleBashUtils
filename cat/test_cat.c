#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parse_flags(int argc, char **argv, int *opt, int *bflag, int *eflag,
                int *nflag, int *sflag, int *tflag, int *vflag);
void parse_GNU_flags(int argc, char **argv, int *bflag, int *eflag,
                int *nflag, int *sflag, int *tflag); 

int main(int argc, char **argv) {
  int bflag = 0, eflag = 0, nflag = 0, sflag = 0, tflag = 0, vflag = 0, opt;
  //int currentFile = parse_flags(argc, argv, &opt, &bflag, &eflag, &nflag, &sflag, &tflag, &vflag);
  const int bufferSize = 4096;
  char buffer[bufferSize]; 
  FILE *fp;
  while (currentFile <= argc) {
    if (currentFile != argc) {
      fp = fopen(argv[currentFile], "r");
      if (fp == NULL) {
        fprintf(stderr, "%s: %s: No such file or directory", argv[0],
                argv[currentFile]);
        exit(1);
      }
    }
  }

 void parse_flags(int argc, char **argv, int opt, int *bflag, int *eflag,
                  int *nflag, int *sflag, int *tflag, int *vflag) {
    while ((opt = getopt(argc, argv, "benstv?")) != -1) {
      // printf("%d", opt);
      switch (opt) {
        case 'b':
          bflag++;
          break;
        case 'e':
          eflag++;
          break;
        case 'n':
          nflag++;
          break;
        case 's':
          sflag++;
          break;
        case 't':
          tflag++;
          break;
        case 'v':
          vflag++;
          break;
        case '?':
          printf("usage: cat [-bens] [file ...]\n");
          exit(1);
        default:
          parse_GNU_flags(argc, argv, bflag, eflag, nflag, sflag, tflag);
      }
    }
  }

  void parse_GNU_flags(int argc, char **argv, int *bflag, int *eflag,
                int *nflag, int *sflag, int *tflag) {
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        bflag++;
      } else if (strcmp(argv[i], "--number") == 0) {
        nflag++;
      } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
        sflag++;
      } else if (strcmp(argv[i], "-E") == 0) {
        eflag++;
      } else if (strcmp(argv[i], "-T") == 0) {
        tflag++;
    }
  }