#include "node.h"
#include "graph.h"
#include <stdio.h>

int main(){
	Graph nfa;
	initializeGraph(&nfa);
	for(int i = 0; i < 10; i++){
		addVertex(&nfa, i, 0, 0);
	}
	addVertex(&nfa, 10, 1, 1);
	addVertex(&nfa, 11, 0, 1);
	
	autoSetIdStart(&nfa);
	autoSetIdEnds(&nfa);

	char alphabet[3] = {'a', 'b', '3'};
	setAlphabet(&nfa, alphabet, 3);

	Transition transitions[15];
	for(int i = 0; i < 12; i++){
		transitions[i] = initializeTransition(i % 12, (i + 1) % 12, alphabet[i %  3]);
	}
	transitions[12] = initializeTransition(11, 0, 'a');
	transitions[13] = initializeTransition(11, 1, '3');
	transitions[14] = initializeTransition(0, 10, 'b');

	setTransitions(&nfa, transitions, 12);
	addTransition(&nfa, transitions[12]);
	addTransition(&nfa, transitions[13]);
	addTransition(&nfa, transitions[14]);

	printf("Graph:{");
	printGraph(&nfa);
	printf("}\n");
	return 0;
}
