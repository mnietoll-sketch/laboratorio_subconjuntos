#include "node.h"
#include "graph.h"
#include "subset.h"
#include <stdio.h>

int main(){
	Graph nfa, dfa;
	initializeGraph(&nfa);
	initializeGraph(&dfa);
	
	addVertex(&nfa, 0, 1, 0);
	addVertex(&nfa, 1, 0, 0);
	addVertex(&nfa, 2, 0, 0);
	addVertex(&nfa, 3, 0, 0);
	addVertex(&nfa, 4, 0, 0);
	addVertex(&nfa, 5, 0, 0);
	addVertex(&nfa, 6, 0, 0);
	addVertex(&nfa, 7, 0, 0);
	addVertex(&nfa, 8, 0, 0);
	addVertex(&nfa, 9, 0, 0);
	addVertex(&nfa, 10, 0, 1);
	
	autoSetIdStart(&nfa);
	autoSetIdEnds(&nfa);

	char alphabet[3] = {'a', 'b', '3'};
	setAlphabet(&nfa, alphabet, 3);
	
	Transition transitions[13];
	transitions[0] = initializeTransition(0, 1, '3');
	transitions[1] = initializeTransition(0, 7, '3');
	transitions[2] = initializeTransition(1, 2, '3');
	transitions[3] = initializeTransition(1, 4, '3');
	transitions[4] = initializeTransition(2, 3, 'a');
	transitions[5] = initializeTransition(3, 6, '3');
	transitions[6] = initializeTransition(4, 5, 'b');
	transitions[7] = initializeTransition(5, 6, '3');
	transitions[8] = initializeTransition(6, 1, '3');
	transitions[9] = initializeTransition(6, 7, '3');
	transitions[10] = initializeTransition(7, 8, 'a');
	transitions[11] = initializeTransition(8, 9, 'b');
	transitions[12] = initializeTransition(9, 10, 'b');

	setTransitions(&nfa, transitions, 13);

	printf("Graph:{");
	printGraph(&nfa);
	printf("}\n");

	subsetOperation(&nfa, &dfa);
	printf("Graph:{");
	printGraph(&dfa);
	printf("}\n");
	return 0;
}
