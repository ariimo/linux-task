make:
	gcc main.c -o main.o -c
	gcc railfence.c -o railfence.o -c
	gcc -o main main.o railfence.o
