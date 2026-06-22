#include "node.h"
#include "graph.h"
#include <stdio.h>

void initializeVertexSet(VertexSet *vertexSet){
	vertexSet->numVertex = 0;
}
void setIdVertexSet(VertexSet *vertexSet, int id){
	vertexSet->id = id;
}

int setVertexSet(VertexSet *vertexSet, Vertex **vertexes, int size){
	for(int i = 0; i < size; i++){
		if(!insertVertexSet(vertexSet, vertexes[i]))
			return 0;
	}

	return 1;
}

int insertVertexSet(VertexSet *vertexSet, Vertex *vertex){
	if(vertexSet->numVertex == MAX_VERTEXES)
		return 0;
	
	if(NULL != searchVertexSet(vertexSet, vertex))
		return 1;

	vertexSet->set[vertexSet->numVertex] = vertex;
	vertexSet->numVertex++;
	return 1;
}

Vertex *searchVertexSet(VertexSet *vertexSet, Vertex *vertex){
	for(int i = 0; i < vertexSet->numVertex; i++)
		if(vertexSet->set[i]->id == vertex->id)
			return vertexSet->set[i];
	return NULL;
}

int equalVertexSet(VertexSet *vertexSet1, VertexSet *vertexSet2){
	if(vertexSet1->numVertex != vertexSet2->numVertex)
		return 0;
	
	for(int i = 0; i < vertexSet1->numVertex; i++){
			if(searchVertexSet(vertexSet2, vertexSet1->set[i]) == NULL)
			return 0;
	}

	return 1;
}

void transitionVertexSet(VertexSet *input, VertexSet *output, Graph *graph, char c){
	for(int i = 0; i < input->numVertex; i++)
		transitionFunction(graph, input->set[i], c, output);
}

void epsilonClosureVertexSet(VertexSet *vertexSet, Graph *graph){
	VertexSet visited;
	initializeVertexSet(&visited);
	getEpsilonClosureRecursive(graph, &visited, vertexSet);
}

void epsilonAndTransitionVertexSet(VertexSet *input, VertexSet *output, Graph *graph, char c){
	transitionVertexSet(input, output, graph, c);
	epsilonClosureVertexSet(output, graph);
}

void printSet(VertexSet *vertexSet){
	printf("id: %d, numVertex: %d, Vertexes:{", vertexSet->id, vertexSet->numVertex);
	for(int i = 0; i < vertexSet->numVertex - 1; i++){
		printf("\n\tVertex:{");
		printVertex(vertexSet->set[i]);
		printf("},");
	}
	if(vertexSet->numVertex - 1 >= 0){
		printf("\n\tVertex:{");
		printVertex(vertexSet->set[vertexSet->numVertex - 1]);
		printf("}\n");
	}
	printf("}");
}
		

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
	for(int i = 0; i < size; i++)
		if(!addTransition(graph, transitions[i]))
			return 0;

	return 1;
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

int addIdEnd(Graph *graph, int idEnd){
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

int autoSetIdStart(Graph *graph){
	for(int i = 0; i < graph->numVertexes; i++){
		if(graph->vertexes[i].isStart){
			setIdStart(graph, graph->vertexes[i].id);
			return 1;
		}
	}

	return 0;
}

int autoSetIdEnds(Graph *graph){
	for(int i = 0; i < graph->numVertexes; i++){
		if(graph->vertexes[i].isEnd){
			if(!addIdEnd(graph, graph->vertexes[i].id))
				return 0;
		}
	}

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

Vertex *getStart(Graph *graph){
	int idx = getVertexIdx(graph, graph->idStart);
	return &graph->vertexes[idx];
}

int getEpsilonClosure(Graph *graph, VertexSet *input, VertexSet *output){
	VertexSet visited;
	initializeVertexSet(&visited);

	setVertexSet(output, input->set, input->numVertex);

	return getEpsilonClosureRecursive(graph, &visited, output);
}

int getEpsilonClosureRecursive(Graph *graph, VertexSet *visited, VertexSet *input){
	int equal = 0;

	for(int i = 0; i < input->numVertex; i++){
		if(NULL == searchVertexSet(visited, input->set[i])){
			insertVertexSet(visited, input->set[i]);
			
			if(!transitionFunction(graph, input->set[i], EPSILON, input))
				return 0;

		} else{
			equal++;
		}
	}

	if(equal == input->numVertex)
		return 1;

	return getEpsilonClosureRecursive(graph, visited, input);
}

int transitionFunction(Graph *graph, Vertex *vertex, char alpha, VertexSet *vertexSet){
	if(!insertVertexSet(vertexSet, vertex))
		return 0;

	for(int i = 0; i < vertex->numEdges; i++){
		if(vertex->edges[i]->alpha == alpha)
			if(!insertVertexSet(vertexSet, vertex->edges[i]->dest))
				return 0;
	}

	return 1;
}

int isIdEnd(Graph *graph, int id){
	for(int i = 0; i < graph->numEnds; i++){
		if(id == graph->idEnds[i])
			return 1;
	}
	return 0;
}

int searchId(Graph *graph, int id){
	for(int i = 0; i < graph->numVertexes; i++){
		if(id == graph->vertexes[i].id)
			return 1;
	}
	return 0;
}

void getAlphabet(Graph *graph, char *alphabet){
	int i;
	for(i = 0; i < graph->numAlphabet; i++){
		alphabet[i] = graph->alphabet[i];
	}
	alphabet[i] = 0;
}

void printGraph(Graph *graph){
	printf("idStart: %d, Vertexes:{", graph->idStart);
	
	for(int i = 0; i < graph->numVertexes - 1; i++){
		printf("\n\tVertex:{");
		printVertex(&graph->vertexes[i]);
		printf("},");
	}
	if(graph->numVertexes - 1 >= 0){
		printf("\n\tVertex:{");
		printVertex(&graph->vertexes[graph->numVertexes - 1]);
		printf("}\n");
	}
	printf("}, Edges:{");

	for(int i = 0; i < graph->numEdges - 1; i++){
		printf("\n\tEdge:{");
		printEdge(&graph->edges[i]);
		printf("},");
	}
	if(graph->numEdges - 1 >= 0){
		printf("\n\tEdge:{");
		printEdge(&graph->edges[graph->numEdges - 1]);
		printf("}\n");
	}
	printf("}, Alphabet:{");

	for(int i = 0; i < graph->numAlphabet - 1; i++){
		printf("\n\tAlpha:{");
		printf("%c", graph->alphabet[i]);
		printf("},");
	}
	if(graph->numAlphabet - 1 >= 0){
		printf("\n\tAlpha:{");
		printf("%c", graph->alphabet[graph->numAlphabet - 1]);
		printf("}\n");
	}
	printf("}, idEnds:{");

	for(int i = 0; i < graph->numEnds - 1; i++){
		printf("\n\tidEnd:{");
		printf("%d", graph->idEnds[i]);
		printf("},");
	}
	if(graph->numEnds - 1 >= 0){
		printf("\n\tidEnd:{");
		printf("%d", graph->idEnds[graph->numEnds - 1]);
		printf("}\n");
	}
	printf("}");
}
