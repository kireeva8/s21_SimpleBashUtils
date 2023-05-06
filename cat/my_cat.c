#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ptint_args(int argc, char **argv);
int parse_flags(int argc, char **argv, int *bflag, int *eflag, int *nflag, int *sflag, int *tflag);
void open_read_file(int argc, char **argv, int currentFile);

int main(int argc, char **argv) {
    int bflag = 0, eflag = 0, nflag = 0, sflag = 0, tflag = 0;
    int currentFile = parse_flags(argc, argv, &bflag, &eflag, &nflag, &sflag, &tflag);
  //  printf("%d %d %d %d %d", bflag, eflag, nflag, sflag, tflag);
    const int bufferSize = 4096;
    char buffer[bufferSize];
  //  int currentFile = optind;
    //FILE *fp;
}

int parse_flags(int argc, char **argv, int *bflag, int *eflag, int *nflag, int *sflag, int *tflag) {
    int i = 1;
    while (i < argc) {
        if(argv[i][0] == '-') {
            switch (argv[i][1])
            {
            case 'b':
                (*bflag)++;
                break;
            case 'e':
                (*eflag)++;
                break;
            case 'n':
                (*nflag)++;
                break;
            case 's':
                (*sflag)++;
                break;
            case 't':
                (*tflag)++;
            }
        }
        else {
            return(i);
        }
        i++;
    }
}

void open_read_file(int argc, char **argv, int currentFile) {
    FILE *fp;
    while (currentFile <= argc) {
        if (currentFile != argc) {
            fp = fopen(argv[currentFile], "rb");
            if (fp == NULL) {
                fprintf(stderr, "%s: %s: No such file or directory",
                        argv[0], argv[currentFile]);
                exit(1);
            }
        }
    }
}

void ptint_args(int argc, char **argv) {
    int i = 0;
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j] != '\0') {
            putchar(argv[i][j]);
            j++;
        }
        if(i + 1 != argc) {
            putchar(' ');
        }
        i++;
    } 
}
