/** Struct to define a queue; each entry can hold a pointer to anything.
 */
struct queue {
  void **elements; // Pointer to base of queue
  int front;  // Pointer to next free cell;
  int max_cells; // Maximum number of entries in the queue
  int size; // Currently used number of cells
  int rear;
};

typedef struct queue Queue;

// Function prototypes

Queue *create_queue(int max_cells);

void delete_queue(Queue *which_queue);

int push_queue(Queue *which_queue, void *ptr);

void* pop_queue(Queue *which_queue);

void* peek_queue(Queue *which_queue);
