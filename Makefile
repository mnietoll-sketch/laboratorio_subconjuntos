test: main.o node.o node.h
	gcc main.o node.o -o test
	./test
main.o: main.c node.h
	gcc -c -g main.c
node.o: node.c node.h
	gcc -c -g node.c
clean:
	rm *.o test
