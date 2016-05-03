#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "tsort.h"

#define arraySize 10

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
	
	// Define 3 tree structs: one for each sorting method.
	struct tnode *tn1;
	struct tnode *tn2;
	struct tnode *tn3;
	
	int arr1[arraySize];		// Sort with Pre-order
	int arr2[arraySize];		// Sort with In-order
	int arr3[arraySize];		// Sort with Post-order
	
	int i;
	
	// Initialize tree structs
	tn1 = NULL;
	tn2 = NULL;
	tn3 = NULL;
	
	printf("\nEnter Array 1 to be Sorted:\n");
	for (i = 0; i < arraySize; i++) {
		printf("Element %d: ", (i + 1));
		scanf("%d", &arr1[i]);
		add_tnode(&tn1, arr1[i]);
	}
	
	printf("\nPre-order traversal of tree (Array 1):\n");
	preorder(tn1);
	printf("\nFree tree: Pre-order:\n");
	deletePre(tn1);
	
	printf("\nEnter Array 2 to be Sorted:\n");
	for (i = 0; i < arraySize; i++) {
		printf("Element %d: ", (i + 1));
		scanf("%d", &arr2[i]);
		add_tnode(&tn2, arr2[i]);
	}
	
	printf("\nIn-order traversal of tree (Array 2):\n");
	inorder(tn2);
	printf("\nFree tree: In-order:\n");
	deleteOrder(tn2);
	
	printf("\nEnter Array 3 to be Sorted:\n");
	for (i = 0; i < arraySize; i++) {
		printf("Element %d: ", (i + 1));
		scanf("%d", &arr3[i]);
		add_tnode(&tn3, arr3[i]);
	}
	
	printf("\nPost-order traversal of tree (Array 3):\n");
	postorder(tn3);
	printf("\nFree tree: Post-order:\n");
	deletePost(tn3);

  return 0;
}
