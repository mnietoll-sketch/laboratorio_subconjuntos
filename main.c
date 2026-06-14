#include "node.h"
#include <stdio.h>

int main(){
	Vertex vertexes[MAX_EDGES];
	for(int i = 0; i < MAX_EDGES; i++){
		initializeVertex(&vertexes[i], i, 0, 0);
	}
	vertexes[0].isStart = vertexes[MAX_EDGES - 1].isEnd = 1;

	Edge edges[MAX_EDGES - 1];
	for(int i = 0; i < MAX_EDGES - 1; i++){
		initializeEdge(&edges[i], &vertexes[i], &vertexes[i + 1], 'a');
		addEdge(&vertexes[i], &edges[i]);
	}

	for(int i = 0; i < MAX_EDGES; i++){
		printf("Vertex{");
		printVertex(&vertexes[i]);
		printf("}\n");
	}
}
