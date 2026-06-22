#include "node.h"
#include "graph.h"
#include "subset.h"
#include <stdio.h>

int main(){
	Graph nfa, dfa;
	initializeGraph(&nfa);
	initializeGraph(&dfa);
	for(int i = 0; i < 10; i++){
		addVertex(&nfa, i, 0, 0);
	}
	addVertex(&nfa, 10, 1, 1);
	addVertex(&nfa, 11, 0, 1);
	
	autoSetIdStart(&nfa);
	autoSetIdEnds(&nfa);

	char alphabet[3] = {'a', 'b', '3'};
	setAlphabet(&nfa, alphabet, 3);

	Transition transitions[25];
	for(int i = 0; i < 12; i++){
		transitions[i] = initializeTransition(i % 12, (i + 1) % 12, alphabet[i %  3]);
	}
	transitions[12] = initializeTransition(11, 2, 'a');
	transitions[13] = initializeTransition(11, 1, '3');
	transitions[14] = initializeTransition(0, 10, 'b');
	transitions[15] = initializeTransition(10, 0, '3');
	transitions[16] = initializeTransition(0, 4, '3');
	transitions[17] = initializeTransition(0, 8, 'b');
	transitions[18] = initializeTransition(0, 2, '3');
	transitions[19] = initializeTransition(1, 0, '3');
	transitions[20] = initializeTransition(11, 5, '3');
	transitions[21] = initializeTransition(4, 10, 'b');
	transitions[22] = initializeTransition(7, 1, '3');
	transitions[23] = initializeTransition(4, 0, 'a');
	transitions[24] = initializeTransition(0, 6, 'a');

	setTransitions(&nfa, transitions, 25);

	printf("Graph:{");
	printGraph(&nfa);
	printf("}\n");

	subsetOperation(&nfa, &dfa);
	printf("Graph:{");
	printGraph(&dfa);
	printf("}\n");
	return 0;
}
