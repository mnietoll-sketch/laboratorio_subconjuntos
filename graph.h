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
	
	Vertex *vertexes[MAX_VERTEXES];
	Edge *edges[MAX_VERTEXES * MAX_EDGES]
	char alphabet[MAX_ALPHABET];
	int idEnds[MAX_VERTEXES];
}

void InitializeGraph(Graph *);

void setIdStart(Graph *, int);
int setVertexes(Graph *, Vertex *, int);
int setEdges(Graph *, Edge *, int);
int setAlphabet(Graph *, char *, int);
int setIdEnds(Graph *, int *, int);

int addVertex(Graph *, Vertex *);
int addEdge(Graph *, Edge *);
int addAlpha(Graph *, char);
int addIdEnd(Graph *, int);
void addTransition(Graph *, int, int, char);

int getVertexIdx(Graph *, int);
void getEpsilonCLosure(Graph *, Vertex *, int, int, char);



#endif
