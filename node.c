#include "node.h"
#include <stdio.h>

void initializeNode(Node *n, int id, int isStart, int isEnd){
	n->id = id;
	n->isStart = isStart;
	n->isEnd = isEnd;
	n->numChildren = 0;
}

Node* addChildren(Node *parent, Node *child){
	if(parent->numChildren == MAX_SIZE)
		return NULL;
	
	parent->children[parent->numChildren] = child;
	parent->numChildren += 1;

	return child;
}

void nodeCopy(Node *dest, Node *src){
	dest->id = src->id;
	dest->isStart = src->isStart;
	dest->isEnd = src->isEnd;
	dest->numChildren = src->numChildren;

	for(int i = 0; i < src->numChildren; i++){
		dest->children[i] = src->children[i];
	}
}

void printNode(Node *n){
	printf("Nodo{id: %d, isStart: %d, isEnd: %d, numChildren: %d} ", n->id, n->isStart, n->isEnd, n->numChildren);
	
	printf("Children{");
	for(int i = 0; i < n->numChildren; i++){
		printf("%d, ", n->children[i]->id);
	}
	printf("}\n");
}
