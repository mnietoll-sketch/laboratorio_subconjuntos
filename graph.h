#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#define MAX_VERTEXES 20
#define MAX_ALPHABET 10

typedef struct Graph Graph;
typedef struct Transition Transition;

struct Transition{
	int idSrc;
	int idDest;
	char alpha;
};

Transition initializeTransition(int, int, char);

struct Graph{
	int idStart;
	int numVertexes;
	int numEdges;
	int numAlphabet;
	int numEnds;
	
	Vertex vertexes[MAX_VERTEXES];
	Edge edges[MAX_VERTEXES * MAX_EDGES];
	char alphabet[MAX_ALPHABET];
	int idEnds[MAX_VERTEXES];
};

void initializeGraph(Graph *);

void setIdStart(Graph *, int);
int setAlphabet(Graph *, char *, int);
int setIdEnds(Graph *, int *, int);
int setTransitions(Graph *, Transition *, int);

int addVertex(Graph *, int, int, int);
int addEdge(Graph *, Vertex *, Vertex *, char);
int addAlpha(Graph *, char);
int addIdEnd(Graph *, int);
int addTransition(Graph *, Transition);

int autoSetIdStart(Graph *);
int autoSetIdEnds(Graph *);
int getVertexIdx(Graph *, int);
void getEpsilonCLosure(Graph *, Vertex *, int, int, char);

void printGraph(Graph *);


#endif
