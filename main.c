#include "node.h"

int main(){
	Node q0, q1, q2;

	initializeNode(&q0, 0, 1, 0);
	initializeNode(&q1, 1, 0, 0);
	initializeNode(&q2, 2, 0, 1);

	addChildren(&q0, &q1);
	addChildren(&q0, &q2);
	addChildren(&q1, &q2);

	printNode(&q0);
	printNode(&q1);
	printNode(&q2);
	return 0;
}
