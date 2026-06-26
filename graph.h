#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#define MAX_VERTEXES 20
#define MAX_ALPHABET 10
#define EPSILON '3'

typedef struct Graph Graph;
typedef struct Transition Transition;
typedef struct VertexSet VertexSet;

struct VertexSet{
	int id;
	int marked;
	int numVertex;
	Vertex *set[MAX_VERTEXES];
};

void initializeVertexSet(VertexSet *);
void markVertexSet(VertexSet *);
void clearVertexSet(VertexSet *);
int isMarkedVertexSet(VertexSet *);
void setIdVertexSet(VertexSet *, int);
int setVertexSet(VertexSet *, Vertex **, int);
int insertVertexSet(VertexSet *, Vertex *);
Vertex *searchVertexSet(VertexSet *, Vertex *);
int equalVertexSet(VertexSet *, VertexSet *);
void transitionVertexSet(VertexSet *, VertexSet *, Graph *, char);
void epsilonClosureVertexSet(VertexSet *, Graph *);
void epsilonAndTransitionVertexSet(VertexSet *, VertexSet *, Graph *, char);
int containsEndVertexSet(VertexSet *);
void printSet(VertexSet *);

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
Vertex *getStart(Graph *);
int getEpsilonClosure(Graph *, VertexSet *, VertexSet *);
int getEpsilonClosureRecursive(Graph *, VertexSet *, VertexSet *);
int transitionFunction(Graph *, Vertex *, char, VertexSet *);
int isIdEnd(Graph *, int);
int searchId(Graph *, int);
void getAlphabet(Graph *, char *);

void printGraph(Graph *);
#endif
