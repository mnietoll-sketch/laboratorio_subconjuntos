#ifndef NODE_H
#define NODE_H

#define MAX_EDGES 10

typedef struct Vertex Vertex;
typedef struct Edge Edge;

struct Edge{
	Vertex *src;
	Vertex *dest;

	char alpha;
};

struct Vertex{
	int id;
	int isStart;
	int isEnd;
	
	int numEdges;
	Edge *edges[MAX_EDGES];
};


void initializeVertex(Vertex *, int, int, int);
void initializeEdge(Edge *, Vertex *, Vertex *, char);

int joinVertexEdge(Vertex *, Edge *);
void printVertex(Vertex *);
void printEdge(Edge *);
#endif
