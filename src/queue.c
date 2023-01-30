#include "queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct Queue_t {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    return queue;
}

void deleteQueue(Queue* queue) {
    assert(queue);
    free(queue);
}

void queue_enqueue(Queue* queue, int value) {
    assert(queue);
    if(queue->front==queue->rear && queue->front==-1) {
        queue->front=queue->rear=0;
        queue->data[queue->rear] = value;
        queue->size++;
    } else if(queue->rear>=queue->front && queue->rear<(QUEUE_SIZE-1)) {
        queue->rear++;
        queue->data[queue->rear] = value;
        queue->size++;
    } else if(queue->rear>=queue->front && queue->rear==(QUEUE_SIZE-1) && queue->size < QUEUE_SIZE) {
        queue->rear = 0;
        queue->data[queue->rear] = value;
        queue->size++;
    } else if(queue->rear<queue->front && queue->size < QUEUE_SIZE) {
        queue->rear++;
        queue->data[queue->rear] = value;
        queue->size++;
    } else {
        printf("No space in queue");
    }
}

int queue_dequeue(Queue* queue, int *value) {
    assert(queue);
    if(queue->front==queue->rear && queue->front==-1) {
        printf("Empty queue");
        return -1;
    } else if(queue->front<queue->rear) {
        *value = queue->data[queue->front];
        queue->front++;
        queue->size--;

        if(queue->front==queue->rear) {
            queue->front=queue->rear=-1;
        }
        return 0;
    } else if(queue->front>queue->rear && queue->front<(QUEUE_SIZE-1) && queue->size > 0 ) {
        *value = queue->data[queue->front];
        queue->front++;
        queue->size--;
        return 0;

    } else if(queue->front>queue->rear && queue->front==(QUEUE_SIZE-1) && queue->size > 0 ) {
        *value = queue->data[queue->front];
        queue->front = 0;
        queue->size--;
        return 0;
    } else {
        printf("Empty queue !");
        return -1;
    }
    return -1;
}

int queue_size(Queue* queue) {
    assert(queue);
    return queue->size;
}

bool queue_isEmpty(Queue* queue) {
    assert(queue);
    return (!queue->size)?:0;
}

void queue_display(Queue* queue) {
    assert(queue);
    if(queue->front<=queue->rear && queue->size>0) {
        for(int i=queue->front; i<queue->rear; ++i) {
            printf("%d ", queue->data[i]);
        }
    } else {
        for(int i=queue->front; i<QUEUE_SIZE; ++i) {
            printf("%d ", queue->data[i]);
        }
        for(int i=0; i<queue->rear; ++i) {
            printf("%d ", queue->data[i]);
        }
    }

    printf("\n");
}
