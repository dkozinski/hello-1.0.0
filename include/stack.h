#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

#define STACK_SIZE 10

typedef struct Stack_t Stack;

/**
 * @brief Create a Stack object
 *
 * @return Stack*
 */
Stack* createStack();

/**
 * @brief Delete the stack object
 *
 * @param stack
 */
void deleteStack(Stack* stack);

/**
 * @brief insert the element at one end of the stack called top
 *
 * @param stack
 * @param node
 */
void stack_push(Stack* stack, int value);

/**
 * @brief remove and return the element at the top of the stack, if it is not empty
 *
 * @param stack
 * @param node
 */
int stack_pop(Stack* stack, int *value);

/**
 * @brief Return the element at the top of the stacke without removing it, if it is not empty
 *
 * @param list
 * @param node
 */
int stack_peek(Stack* stack);

/**
 * @brief return the number of elements in the stack
 *
 * @return int
 */
int stack_size(Stack* stack);

/**
 * @brief Return true if the stack is not empty, otherwise false
 *
 * @return true
 * @return false
 */
bool stack_isEmpty(Stack* stack);

/**
 * @brief Dispaly stack
 *
 * @param stack
 */
void stack_display(Stack* stack);

#endif // _STACK_H