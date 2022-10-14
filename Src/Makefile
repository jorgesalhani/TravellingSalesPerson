all: cidade.o lista.o viagem.o pilha.o main.o
	gcc -g cidade.o lista.o viagem.o pilha.o main.o -o exec -std=c99 -Wall; make clean

cidade.o:
	gcc -g -c cidade.c -o cidade.o

lista.o:
	gcc -g -c lista.c -o lista.o

viagem.o:
	gcc -g -c viagem.c -o viagem.o

pilha.o:
	gcc -g -c pilha.c -o pilha.o

main.o:
	gcc -g -c main.c -o main.o

clean:
	rm *.o
	
run:
	./exec < ../TestCases/4.in