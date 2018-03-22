

all :	main.o api.o grammar.o check.o
	gcc -o main main.o api.o grammar.o check.o

main.o : main.c
	gcc -c -ggdb main.c

api.o :grammar.h api.h
	gcc -c -ggdb api.c

grammar.o : grammar.h
	gcc -c -ggdb grammar.c

check.o: check.h
	gcc -c -ggdb check.c

clean:
	rm -rf *.o
