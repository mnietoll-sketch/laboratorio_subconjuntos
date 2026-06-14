#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#define MAX_VERTEXES 20
#define MAX_ALPHABET 10

typedef struct Graph Graph;

struct Graph{
	int idStart;
	int numVertexes;
	int numEdges;
	int numAlphabet;
	int numEnds;
	
	Vertex vertexes[MAX_VERTEXES];
	Edge edges[MAX_VERTEXES * MAX_EDGES]
	char alphabet[MAX_ALPHABET];
	int idEnds[MAX_VERTEXES];
}

setIdStart();
addIdEnd();
addVertex();
addEdge();
addAlpha();
addTransition();
getIdx();
getEpsilonCLosure();



#endif
