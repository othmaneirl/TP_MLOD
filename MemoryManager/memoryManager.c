// Compilation
// gcc -g --std=c99 -W -Wall memoryManager.c

// Exécution
// ./a.out

// Détection de fuites mémoires
// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./a.out

#include "linkedList.h"
#include "linkedList.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// définir le type Bloc
// (facultatif) définir le type BlocList

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// définir le type MemoryManager

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 3
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// createMemoryManager(startAddress,maxSize)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 4
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// myalloc(MemoryManager, size)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 5
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// myfree(MemoryManager, address)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 6
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void simpleMain() {
	MemoryManager memoryManager = createMemoryManager(0,100);
	myalloc(memoryManager, 8);
	myalloc(memoryManager, 15);
	myalloc(memoryManager, 5);
	printf("L'espace mémoire restant est %d\n", memoryManager->freeList->val->maxSize);
	myfree(memoryManager, 8);
	printf("L'espace mémoire restant est %d\n", memoryManager->freeList->val->maxSize);
	readFromFile("memorySimulation-small.txt",memoryManager, 5);
	printf("L'espace mémoire restant est %d\n", memoryManager->freeList->val->maxSize);
	myfree(memoryManager,15);
	myfree(memoryManager,5);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 7
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// void readFromFile(...) {
//
// }

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 8
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// defragmentation(memoryManager)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char *argv[]) {

	// 6
	simpleMain();

	// 7
	

	return 0;
}
