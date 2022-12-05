all: prog.e

prog.e: main.o util.o operacoes.o
	gcc -o prog.e main.o util.o operacoes.o

main.o: main.c
	gcc -o main.o -c main.c

util.o: util.c 
	gcc -o util.o -c util.c

operacoes.o: operacoes.c
	gcc -o operacoes.o -c operacoes.c

clean:
	rm -f *.o prog.e		
	