#include "node.h"
#include "graph.h"

Transition initializeTransition(int idSrc, int idDest, char alpha){
	Transition result;
	result.idSrc = idSrc;
	result.idDest = idDest;
	result.alpha = alpha;

	return result;
}

void initializeGraph(Graph *graph){
	graph->numVertexes = 0;
	graph->numEdges = 0;
	graph->numAlphabet = 0;
	graph->numEnds = 0;
}

void setIdStart(Graph *graph, int idStart){
	graph->idStart = idStart;
}

int setAlphabet(Graph *graph, char *alphabet, int size){
	if(size  > MAX_ALPHABET)
		return 0;

	for(int i = 0; i < size; i++)
		graph->alphabet[i] = alphabet[i];

	graph->numAlphabet = size;
	return 1;
}

int setIdEnds(Graph *graph, int *idEnds, int size){
	if(size > MAX_VERTEXES)
		return 0;

	for(int i = 0; i < size; i++)
		graph->idEnds[i] = idEnds[i];

	graph->numEnds = size;
	return 1;
}

int setTransitions(Graph *graph, Transition *transitions, int size){
	int result = 1;

	for(int i = 0; i < size; i++)
		result *= addTransition(graph, transitions[i]);

	return result;
}

int addVertex(Graph *graph, int id, int isStart, int isEnd){
	if(graph->numVertexes == MAX_VERTEXES)
		return 0;

	initializeVertex(&graph->vertexes[graph->numVertexes], id, isStart, isEnd);
	graph->numVertexes++;
	return 1;
}

int addEdge(Graph *graph, Vertex *src, Vertex *dest, char alpha){
	if(graph->numEdges == MAX_VERTEXES * MAX_EDGES)
		return 0;

	initializeEdge(&graph->edges[graph->numEdges], src, dest, alpha);
	graph->numEdges++;
	return 1;
}

int addAlpha(Graph *graph, char alpha){
	if(graph->numAlphabet == MAX_ALPHABET)
		return 0;

	graph->alphabet[graph->numAlphabet] = alpha;
	graph->numAlphabet++;
	return 1;
}

int addEnd(Graph *graph, int idEnd){
	if(graph->numEnds == MAX_VERTEXES)
		return 0;

	graph->idEnds[graph->numEnds] = idEnd;
	graph->numEnds++;
	return 1;
}

int addTransition(Graph *graph, Transition transition){
	int idxSrc, idxDest;
	char alpha;
	Vertex *src, *dest;

	idxSrc = getVertexIdx(graph, transition.idSrc);
	idxDest = getVertexIdx(graph, transition.idDest);
	alpha = transition.alpha;

	src = &graph->vertexes[idxSrc];
	dest = &graph->vertexes[idxDest];

	if(!addEdge(graph, src, dest, alpha))
		return 0;

	if(!joinVertexEdge(src, &graph->edges[graph->numEdges - 1]))
		return 0;

	return 1;
}

int getVertexIdx(Graph *graph, int id){
	int result;

	for(int i = 0; i < graph->numVertexes; i++){
		if(id == graph->vertexes[i].id)
			result = i;
	}

	return result;
}
