

s1=12
s2=245
exo3_run:
	valgrind ./exo2__2 ${s1}
	valgrind ./exo2__2 ${s2}
exo3_run0: exo3_run01 exo3_run1
exo3_run01: exo2__2
	./exo2__2 ${s1}
exo3_run02: exo2__2
	./exo2__2 ${s2}
exo2_run: exo2
	valgrind ./exo2 $(s1)
	valgrind ./exo2 $(s2)
exo2_run0: exo2_run1 exo2_run2
exo2_run1:exo2
	./exo2 $(s1)
exo2_run2:exo2
	./exo2 $(s2)
exo1_run: exo1
	valgrind ./exo1
exo1: ./exo1.c ./exo1.h
	gcc $< -o $@
exo2_1.o: ./lelement.c
	gcc -c -std=c99 -g $< -o $@
exo2_2.o: ./hashtable.c
	gcc -c -std=c99 -g $< -o $@
exo2_2__2.o: ./hashtable2.c ./hashtable2.h
	gcc -c -std=c99 -g $< -o $@
exo2: exo2_1.o exo2_2.o ./test_api_table_hashage.c
	gcc -std=c99 -g $^ -o $@
exo2__2: exo2_1.o exo2_2__2.o ./test_api_table_hashage2.c
	gcc -std=c99 -g $^ -o $@
clean:
	rm -f a.out *.o *.c~ *.h~ *.txt~ Makefile~ exo1 exo2 *.sh~ exo2__2
