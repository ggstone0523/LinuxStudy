all: Heap Stack

Heap: Heap.o
	gcc -o Heap Heap.o

Heap.o: Heap.c
	gcc -O -c -o Heap.o Heap.c

Stack: Stack.o
	gcc -o Stack Stack.o

Stack.o:
	gcc -O -c -o Stack.o Stack.c

clean:
	rm -rf Heap.o Stack.o
