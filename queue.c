#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/** Create a queue by allocating a Queue structure, initializing it,
 *  and allocating memory to hold the queue entries.
 * @param max_cells Maximum entries in the queue
 * @return Pointer to newly-allocated Queue structure, NULL if error.
 */
Queue *create_queue(int max_cells) {
  Queue *new_queue; // Holds pointer to the newly-allocated Queue structure.
  new_queue = (Queue *) malloc(sizeof(Queue)); 

  if (new_queue == NULL) return NULL; // Error--unable to allocate.

  // Fill in the struct
  new_queue->max_cells = max_cells;
  new_queue->size = 0; // Empty to start
  new_queue->front = 0;
  new_queue->rear = -1;

  // Now allocate space for the queue entries.
  new_queue->elements = (void **) calloc(max_cells, sizeof(void *));
  if (new_queue->elements == NULL) {
    free(new_queue); // Unable to allocate queue entries, so free struct.
    return NULL;
  }
  
  return new_queue;
}

/** Deletes a queue, including the structure and the memory
 * for holding the queue entries, but not the entries themselves.
 * @param which_queue Pointer to Queue structure.
 */
void delete_queue(Queue *which_queue) {
  free(which_queue->elements); // Free memory block with queue entries.
  free(which_queue); // Then free the struct.
}

/** Pushes a pointer onto a Queue.
 * @param which_queue Pointer to queue you want to push onto.
 * @param ptr Pointer to be pushed.
 * @return 0 if successful, -1 if not.
 */
int push_queue(Queue *which_queue, void *ptr) {
  // Check if queue is already full 
  if ((which_queue->size) == (which_queue->max_cells)) {
    printf("WARNING: The queue is full. Last entry was not entered to queue.\n");
    return -1;  // Queue overflow.
  } else {
	(which_queue->size)++; 
	(which_queue->rear)++;
	
	if(which_queue->rear == which_queue->max_cells) {
		which_queue->rear = 0;
	}
	
	which_queue->elements[which_queue->rear] = ptr;
  }

  
  
  return 0;  // Success
}

/** Pops top of queue, and returns it.
 * @param which_queue Pointer to Queue you want to pop from.
 * @return Bottom entry of the queue, NULL if queue is empty.
 */
void* pop_queue(Queue *which_queue) {
  // Check if queue is empty
  if ((which_queue->size) == 0) {
    which_queue->size = 0; // Fix
    return NULL;  // Queue empty
  } else {
	(which_queue->front)++;         // Remember, this points to next free cell
	(which_queue->size)--;  
	
	if(which_queue->front == which_queue->max_cells) {
		which_queue->front = 0;
		return which_queue->elements[which_queue->max_cells - 1];
	}
  }

  // Pop from queue.
  
  return (which_queue->elements[(which_queue->front) - 1]);
}

