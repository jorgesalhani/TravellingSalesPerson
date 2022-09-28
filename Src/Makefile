all: item.o listaAdjacencia.o main.o
	gcc -g item.o listaAdjacencia.o main.o -o exec -std=c99 -Wall; make clean

main.o:
	gcc -g -c main.c -o main.o

item.o:
	gcc -g -c item.c -o item.o

listaAdjacencia.o:
	gcc -g -c listaAdjacencia.c -o listaAdjacencia.o

clean:
	rm *.o
	
run:
	valgrind ./exec < ../TestCases/1.in