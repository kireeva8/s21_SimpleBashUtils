#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    bool b, e, n, s, t;
    bool error;
} cat_flags;

bool cat_no_args(int fd, char *name);
bool cat_args(int argc, char **argv);
bool parse_flags(cat_flags flag, char *argv, char *name);

int main(int argc, char **argv) {
    if (argc == 1) {
        if (!cat_no_args(STDIN_FILENO, argv[0])) { //if можно убрать , хз зачем он
            return 1;
        } //разобраться
    }
    else {
        if (cat_args(argc, argv)) { 
           return 1;
        }
    }
    
}

bool cat_no_args(int fd, char *name) {
    char buf[4096]; 
    int bytes_read;

    if (fd == -1) {
       // flag.error = false;
        perror(name); // выведет соответсвующие сообщение об ошибке
    }

    bytes_read = read(fd, buf, 4096); // возвращает 1 или -1
    while (bytes_read > 0) {
        printf("%.*s", bytes_read, buf);
        bytes_read = read(fd, buf, 4096);
    }
    return bytes_read != -1; // если stdin не существует (обработка ошибки)
                          //если не равно -1, значит все выполнилась правильно, вернется тру, иначе фолс
}

bool cat_args(int argc, char **argv) {
    cat_flags flag = {0, 0, 0, 0, 0};
    for (int i = 1; i != argc; ++i) {
        if (*argv[i] == '-') {
            if (!parse_flags(flag, argv[i], argv[0])) {
              //  flag.error = false;
                return false;
            }
        }
    }
    if (!(flag.b + flag.e + flag.n + flag.s + flag.t)) {
        for (int i = 1; i != argc; ++i) {
            if (*argv[i] != '-') {
                cat_no_args(open (argv[i], O_RDONLY), argv[0]);
                return false;
            }
        }
    }
    return true;
}

bool parse_flags(cat_flags flag, char *argv, char *name) {
    argv++; //  пропускаем первый '-'
    if (*argv == '-') {
        argv++;
        if (strcmp(argv, "number-nonblank") == 0) {
            flag.b = true;
        }
        else if (strcmp(argv, "number") == 0) {
            flag.n = true;
        }
        else if (strcmp(argv, "squeeze-blank") == 0) {
            flag.s = true;
        }
        else {
            dprintf(STDERR_FILENO, "%s: illegal option '--%s'\n", name, argv);
        }
        return true;
    }
    for(char *i = argv; *i != '\0'; ++i) {
        switch (*i) {
           case 'b':
                flag.b = true;
                break;
            case 'e':
                flag.e = true;
                break;
            case 'n':
                flag.n = true;
                break;
            case 's':
                flag.s = true;
                break;
            case 't':
                flag.t = true;
                break;
            default:
                dprintf(STDERR_FILENO, "%s: %s '%s'\n", name, "illegal option --", argv);
                 // flag.error = false;
                return false;
         }
      }
      return true;
}