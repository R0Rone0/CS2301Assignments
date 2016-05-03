#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stack.h"

#define MAX_STACK_SIZE 5

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
	
  int i;
  int stack_cnt = 0;
  const int max_entries = (MAX_STACK_SIZE - 1); // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;
  int push_stat; // Returned status from push

  // First, create a stack
  Stack *new_stack = create_stack(max_entries);
  if (!new_stack) {
    fprintf(stderr, "Unable to create stack. Error = %d: %s\n",
            errno, strerror(errno));
    return 1;
  }


  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push_stat = push(new_stack, (void *) new_foo1);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push_stat = push(new_stack, (void *) new_foo2);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  if (returned_foo) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  returned_foo = (Foo *) pop(new_stack);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }
  
  printf("\nNEW TESTS\n\n");
  
  // Push 2 Foos on, Pop 1 Foo off, Push 1 more on
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 20;
  new_foo2->y = 9.81659;
  //stack_cnt++;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push_stat = push(new_stack, (void *) new_foo2);
  if (push_stat) {
    printf("Stack is full.\n");
  }
  
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 21;
  new_foo2->y = 7.28375;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push_stat = push(new_stack, (void *) new_foo2);
  if (push_stat) {
    printf("Stack is full.\n");
  }
  
  returned_foo = (Foo *) pop(new_stack);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }
  
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 22;
  new_foo2->y = 6.39238;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push_stat = push(new_stack, (void *) new_foo2);
  if (push_stat) {
    printf("Stack is full.\n");
  }
  
  // Push more than 5 Foos to stack
  for(i = 10; i > 0 ; i--) {
	  new_foo2 = (Foo *) malloc(sizeof(Foo));
	  new_foo2->x = i;
	  new_foo2->y = i + 2.47383;
	  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
	  push_stat = push(new_stack, (void *) new_foo2);
	  if (push_stat == -1) {
		printf("WARNING: Stack is full. Last entry was NOT entered into stack.\n");
		break;
		}
  }
  
  // Pop Foos until there are none left in stack
  for(i = MAX_STACK_SIZE; i > 0; i--) {
	  returned_foo = (Foo *) pop(new_stack);
	  if (returned_foo) {
		printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
	  } else {
		break;
	  }
  }
  
  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);
  
  return 0;
}
