#ifndef NODE_H
#define NODE_H
#define MAX_SIZE 10

typedef struct Node{
	int id;
	int isStart;
	int isEnd;

	struct Node *children[MAX_SIZE];
	int numChildren;
} Node;

void initializeNode(Node *, int, int, int);
Node* addChildren(Node *, Node *);
void nodeCopy(Node *, Node *);
void printNode(Node *);
#endif
