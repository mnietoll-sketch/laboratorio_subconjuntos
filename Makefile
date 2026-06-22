test: main.o node.o node.h graph.o graph.h subset.o subset.h
	gcc main.o node.o graph.o subset.o -o test
main.o: main.c node.h
	gcc -c -g main.c
node.o: node.c node.h
	gcc -c -g node.c
graph.o: graph.c graph.h node.h
	gcc -c -g graph.c
subset.o: subset.c subset.h graph.h node.h
	gcc -c -g subset.c
clean:
	rm *.o test
