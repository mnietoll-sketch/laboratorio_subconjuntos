#include "node.h"
#include "graph.h"
#include "subset.h"

#include <stdio.h>
#include <stdlib.h>

void initializationSet(Set *set){
	set->num = 0;
}

VertexSet *selectNotMarkedSet(Set *set){
	for(int i = 0; i < set->num; i++)
		if(set->arr[i]->marked == 0)
			return set->arr[i];
	return NULL;
}

int equalSet(Set *set1, Set *set2){
	if(set1->num != set2->num)
		return 0;

	for(int i = 0; i < set1->num; i++){
		if(searchSet(set2, set1->arr[i]) == NULL)
			return 0;
	}

	return 1;
}

VertexSet *searchSet(Set *set, VertexSet *vertexSet){
	for(int i = 0; i < set->num; i++){
		if(equalVertexSet(set->arr[i], vertexSet))
			return set->arr[i];
	}

	return NULL;
}

int insertSet(Set *set, VertexSet *vertexSet){
	if(set->num == MAX_VERTEXES)
		return 0;

	if(searchSet(set, vertexSet) == NULL){
		set->arr[set->num] = vertexSet;
		set->num++;
	}
	return 1;
}

VertexSet *getSet(Set *set, int id){
	for(int i = 0; i < set->num; i++)
		if(set->arr[i]->id == id)
			return set->arr[i];
	return NULL;
}

void insertOperation(Set *set, Graph *graph, VertexSet* vertexSets, int *id, int isStart, int isEnd){
	addVertex(graph, *id, isStart, isEnd);
	if(isStart)
		setIdStart(graph, *id);
	insertSet(set, &vertexSets[*id]);
	(*id)++;
}

void startOperation(Graph *nfa, Graph *dfa, Set *set, VertexSet *vertexSets, int *id){
	char alphabet[MAX_ALPHABET];
	getAlphabet(nfa, alphabet);
	for(int i = 0; i < nfa->numAlphabet; i++){
		if(alphabet[i] == EPSILON)
			alphabet[i] = alphabet[nfa->numAlphabet - 1];
		break;
	}
	setAlphabet(dfa, alphabet, nfa->numAlphabet - 1);

	Vertex *nfaStart = getStart(nfa);
	insertVertexSet(&vertexSets[*id], nfaStart);
	epsilonClosureVertexSet(&vertexSets[*id], nfa);

	insertOperation(set, dfa, vertexSets, id, 1, 0);
}

void subsetOperation(Graph *nfa, Graph *dfa){
	VertexSet *vertexSets = (VertexSet *)malloc((MAX_VERTEXES + 1) * sizeof(VertexSet));
	for(int i = 0; i < (MAX_VERTEXES + 1); i++){
		initializeVertexSet(&vertexSets[i]);
		setIdVertexSet(&vertexSets[i], i);
	}

	Set set;
	initializationSet(&set);

	int id = 0;
	
	startOperation(nfa, dfa, &set, vertexSets, &id);

	VertexSet *it;
	while((it = selectNotMarkedSet(&set)) != NULL){
		markVertexSet(it);
		for(int i = 0; i < dfa->numAlphabet; i++){
			epsilonAndTransitionVertexSet(it, &vertexSets[id], dfa, dfa->alphabet[i]);

			VertexSet *foundedVertexSet;
			if((foundedVertexSet = searchSet(&set, &vertexSets[id])) == NULL){
				if(containsEndVertexSet(&vertexSets[id]))
					insertOperation(&set, dfa, vertexSets, &id, 0, 1);
				else
					insertOperation(&set, dfa, vertexSets, &id, 0, 0);
				Transition transition;
				transition = initializeTransition(it->id, id - 1, dfa->alphabet[i]);
				addTransition(dfa, transition);
			} else{
				Transition transition;
				transition = initializeTransition(it->id, foundedVertexSet->id, dfa->alphabet[i]);
				addTransition(dfa, transition);
				clearVertexSet(&vertexSets[id]);
			}
		}
	}
	autoSetIdEnds(dfa);
	free(vertexSets);
}

