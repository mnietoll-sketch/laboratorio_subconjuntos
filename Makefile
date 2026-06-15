test: main.o node.o node.h graph.o graph.h
	gcc main.o node.o graph.o -o test
main.o: main.c node.h
	gcc -c -g main.c
node.o: node.c node.h
	gcc -c -g node.c
graph.o: graph.c graph.h node.h
	gcc -c -g graph.c
clean:
	rm *.o test
