#include <stdlib.h>
#include <stdio.h>
#include "tsort.h"

/** Adds tree node to specified tree.
 * @param[in] src Pointer to beginning of tree.
 * @param[in] num Holds random int value determined by user and rand_gen.
 */
void add_tnode(struct tnode **src, int num) {
	if(*src == NULL) {
		*src = malloc(sizeof(struct tnode));
		
		(*src)->leftChild = NULL;
		(*src)->data = num;
		(*src)->rightChild = NULL;
	} else {
		if(num < (*src)->data) {
			add_tnode(&((*src)->leftChild), num);
		} else {
			add_tnode(&((*src)->rightChild), num);
		}
	}
}

/** Random number generator function. Returns rand number.
 * @return number, Random number
 */
int rand_gen(void) {
	int number;	// variable to store random number

	number = rand();
	
	return number;
	
}


/** Populate random array function. Populates given array with random numbers.
 * @param[in] a Pointer to array to be populated
 * @param[in] arraySize Size of array to be populated
 */
void populate_array(int* a, int arraySize) {
	int i;
	
	/*
	  FOR loop to populate array with random numbers
	  FOR loop will break out when:
	  1) number of elements in array equals specified arraySize (i < arraySize)
	*/
	for(i = 0; i < arraySize; i++) {
		a[i] = rand_gen();
	}
}

/** Sorts given tree in descending order using Pre-Order algorithm.
 * @param[in] src Pointer to tree node to begin sort.
 */
void preorder(struct tnode *src) {
	if(src != NULL) {
		printf("%d\n", src->data);
		preorder(src->rightChild);
		preorder(src->leftChild);
	}
}

/** Sorts given tree in descending order using In-Order algorithm.
 * @param[in] src Pointer to tree node to begin sort.
 */
void inorder(struct tnode *src) {
	if(src != NULL) {
		inorder(src->rightChild);
		printf("%d\n", src->data);
		inorder(src->leftChild);
	}
}

/** Sorts given tree in descending order using Post-Order algorithm
 * @param[in] src Pointer to tree node to begin sort.
 */
void postorder(struct tnode *src) {
	if(src != NULL) {
		postorder(src->rightChild);
		postorder(src->leftChild);
		printf("%d\n", src->data);
	}
}

/** Deletes tree to free memory using Pre-Order algorithm.
 * @param[in] src Pointer to tree node to begin memory deallocation.
 */
void deletePre(struct tnode *src) {
	if(src == NULL) return;
	
	printf("Deleting node: %d\n", src->data);
	deletePost(src->rightChild);
	deletePost(src->leftChild);
	free(src);
}

/** Deletes tree to free memory using In-Order algorithm.
 * @param[in] src Pointer to tree node to begin memory deallocation.
 */
void deleteOrder(struct tnode *src) {
	if(src == NULL) return;
	
	deletePost(src->rightChild);
	printf("Deleting node: %d\n", src->data);
	deletePost(src->leftChild);
	free(src);
}

/** Deletes tree to free memory using Post-Order algorithm.
 * @param[in] src Pointer to tree node to begin memory deallocation.
 */
void deletePost(struct tnode *src) {
	if(src == NULL) return;
	
	deletePost(src->rightChild);
	deletePost(src->leftChild);
	printf("Deleting node: %d\n", src->data);
	free(src);
}
