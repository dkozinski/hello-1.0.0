#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 10

typedef struct Queue_t Queue;

Queue* createQueue();
void deleteQueue(Queue* Queue);

void queue_enqueue(Queue* Queue, int value);
int queue_dequeue(Queue* Queue, int *value);
int queue_size(Queue* Queue);
bool queue_isEmpty(Queue* Queue);
void queue_display(Queue* Queue);

#endif // _QUEUE_H