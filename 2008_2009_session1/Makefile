CC = gcc
CFLAGS-= -std=c99 -g

all2: test_exo2_run
all3: bt2
	valgrind ./bt2
all: exo1_exec2
link_tests: link.o link_tests.c
	$(CC) $^ -o $@
run_link_tests: link_tests
	valgrind ./link_tests
exo1.o: correction.c
	$(CC) -c $(CFLAGS) $< -o $@
exo1_exec: exo1.o
	$(CC) $< -o $@
exo1_exec2: exo1_exec
	./exo1_exec
link.o: ./link.c ./link.h
	gcc -std=c99 -g -c link.c
file.o: ./file.c ./file.h
	gcc -std=c99 -g -c file.c
test_exo2: link.o file.o file_tests.c
	gcc -std=c99 -g file_tests.c link.o file.o -o $@
test_exo2_run: test_exo2
	valgrind --leak-check=full ./test_exo2
bt2: ./bintree.c ./test_api_bt.c 
	$(CC) -DSECOND=2 $(CFLAGS) $^ -o $@
clean:
	rm -f Makefile~ *.c~ *.h~ *.o exo1_exec *.txt~ a.out test_exo2 link_tests bt2
