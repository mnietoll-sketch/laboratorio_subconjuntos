#ifndef SUBSET_H
#define SUBSET_H

#include "node.h"
#include "graph.h"

typedef struct Set Set;

struct Set{
	int num;
	VertexSet *arr[MAX_VERTEXES];
};

void initializationSet(Set *);
VertexSet *selectNotMarkedSet(Set *);
int equalSet(Set *, Set *);
VertexSet *searchSet(Set *, VertexSet *);
int insertSet(Set *, VertexSet *);
VertexSet *getSet(Set *, int);

void insertOperation(Set *set, Graph *graph, VertexSet *, int *id, int isStart, int isEnd);
void startOperation(Graph *, Graph *, Set *, VertexSet *, int *);
void subsetOperation(Graph *, Graph *);
#endif
