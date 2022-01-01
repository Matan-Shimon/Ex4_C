all: Graphlabel graph

graph: main.o Graphclass.a
	gcc -Wall -g -o graph main.o Graphclass.a

Graphlabel: Graphclass.a

Graphclass.a: Graph_Algo.o Graph.o Priority_Queue.o
	ar -rcs Graphclass.a Graph_Algo.o Graph.o Priority_Queue.o

Priority_Queue.o: Priority_Queue.c Priority_Queue.h
	gcc -Wall -g -c Priority_Queue.c

Graph_Algo.o: Graph_Algo.c Graph_Algo.h
	gcc -Wall -g -c Graph_Algo.c

Graph.o: Graph.c Graph.h
	gcc -Wall -g -c Graph.c

main.o : main.c Graph_Algo.h Graph.h Priority_Queue.h
	gcc -Wall -g -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a  graph