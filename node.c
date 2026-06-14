#include "node.h"
#include <stdio.h>

void initializeVertex(Vertex *v, int id, int isStart, int isEnd){
	v->id = id;
	v->isStart = isStart;
	v->isEnd = isEnd;
	v->numEdges = 0;
}

void initializeEdge(Edge *e, Vertex *src, Vertex *dest, char alpha){
	e->src = src;
	e->dest = dest;
	e->alpha = alpha;
}

int addEdge(Vertex *src, Edge *edge){
	if(src->numEdges == MAX_SIZE)
		return 0;

	src->edges[src->numEdges] = edge;
	src->numEdges++;
	return 1;
}

void printVertex(Vertex *v){
	printf("id: %d, isStart: %d, isEnd: %d, numEdges: %d, Edges:{", v->id, v->isStart, v->isEnd, v->numEdges);
	
	for(int i = 0; i < v->numEdges - 1; i++){
		printf("\n\tEdge:{");
		printEdge(v->edges[i]);
		printf("},");
	}
	if(v->numEdges - 1 >= 0){
		printf("\n\tEdge:{");
		printEdge(v->edges[v->numEdges - 1]);
		printf("}\n");
	}

	printf("}");
}

void printEdge(Edge *e){
	printf("src.id: %d, dest.id: %d, alpha: %c", e->src->id, e->dest->id, e->alpha);
}
