#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

void test_linkedlist(void);
void test_stack(void);
void test_queue(void);

int main(void) {

  test_linkedlist();
  test_stack();
  test_queue();

  return 0;
}

void test_linkedlist(void) {

  printf("*** Test Linked List *** \n");

  int choice = 0;
  char item = '\0';

  struct LinkedList* list = createList();

  while(choice != 3) {
    printf("Enter your choice:\n");
    printf("\t1 to insert an element into the end list.\n");
    printf("\t2 to delete an element from the list.\n");
    printf("\t3 to end.\n");

    printf(":: ");
    scanf("%d",  &choice);

    switch(choice) {
      case 1:
        printf("Enter a charcter: ");
        scanf("\n%c",&item);
        // inset element to the list
        printf("Item to add: %c\n", item);
        list_insert(list, item);
        list_display(list);
        break;
      case 2:
        printf("Delete a charcter: ");
        scanf("\n%c",&item);
        // inset element to the list
        printf("Irem to delete: %c\n", item);
        list_delete(list, item);
        list_display(list);
        break;
    }
  }

  destroyList(list);

}

void test_stack(void) {
  printf("*** Test Stack *** \n");

  Stack* stack = createStack();

  stack_push(stack, 1);
  stack_display(stack);

  stack_push(stack, 2);
  stack_display(stack);

  stack_push(stack, 3);
  stack_display(stack);

  stack_push(stack, 4);
  stack_display(stack);

  stack_push(stack, 5);
  stack_display(stack);

  int value;
  stack_pop(stack, &value);
  stack_display(stack);

  stack_pop(stack, &value);
  stack_display(stack);

  deleteStack(stack);
}

void test_queue(void) {
  printf("*** Test Queue *** \n");

  Queue* queue = createQueue();

  queue_enqueue(queue, 1);
  queue_display(queue);

  queue_enqueue(queue, 2);
  queue_display(queue);

  queue_enqueue(queue, 3);
  queue_display(queue);

  queue_enqueue(queue, 4);
  queue_display(queue);

  queue_enqueue(queue, 5);
  queue_display(queue);

  int value;
  queue_dequeue(queue, &value);
  queue_display(queue);

  queue_dequeue(queue, &value);
  queue_display(queue);

  deleteQueue(queue);
}