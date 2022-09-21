all: run
	gcc main.c -g -o exec -std=c99 -Wall

clean:
	rm *.o
	
run:
	valgrind ./exec < ../TestCases/1.in