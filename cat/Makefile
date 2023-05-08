CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: s21_cat
	
s21_cat: 
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: 
	sh test_func_cat.sh

clean:
	rm -f s21_cat *.o

rebuild: clean all