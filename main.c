#include "node.h"
#include <stdio.h>

int main(){
	Vertex vertexes[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++){
		initializeVertex(&vertexes[i], i, 0, 0);
	}
	vertexes[0].isStart = vertexes[MAX_SIZE - 1].isEnd = 1;

	Edge edges[MAX_SIZE - 1];
	for(int i = 0; i < MAX_SIZE - 1; i++){
		initializeEdge(&edges[i], &vertexes[i], &vertexes[i + 1], 'a');
		addEdge(&vertexes[i], &edges[i]);
	}

	for(int i = 0; i < MAX_SIZE; i++){
		printf("Vertex{");
		printVertex(&vertexes[i]);
		printf("}\n");
	}
}
