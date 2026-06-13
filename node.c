#include "node.h"

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
