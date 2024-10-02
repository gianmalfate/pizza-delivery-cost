all: main.o graph.o
	@gcc main.o graph.o -o main

main.o: main.c
	@gcc main.c -c

graph.o: graph.c
	@gcc graph.c -c

run:
	@./main