#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    char data;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct LinkedList* createList() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void destroyList(struct LinkedList* list) {
    assert(list);
    struct Node* node = list->head;
    struct Node* prev_node = NULL;
    printf("deleting nodes: ");
    while(node) {
        if(node==list->tail) {
            printf("%c ", node->data);
            free(node);
            if(prev_node) {
                prev_node->next = NULL;
            }
            list->tail = prev_node;

            node = list->head;
            prev_node = NULL;
        } else {
            prev_node = node;
            node = node->next;
        }
    }
    printf("\n");

    free(list);
}

void list_insert(struct LinkedList* list, char data) {
    assert(list);
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if(list->size == 0) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

int list_delete(struct LinkedList* list, char data) {
    assert(list);
    if(list->size) {
        struct Node* node = list->head;
        struct Node* prev_node = NULL;

        while(node) {
            if(node->data==data) {
                break;
            }
            prev_node = node;
            node = node->next;
        }
        if(!node) return EXIT_FAILURE;

        if(node==list->head && node==list->tail) {
            list->head = list->tail = NULL;
            list->size--;
            free(node);
            return EXIT_SUCCESS;
        }
        if(node==list->head) {
            list->head = list->head->next;
            list->size--;
            free(node);
            return EXIT_SUCCESS;
        }
        if(node==list->tail) {
            prev_node->next = NULL;
            list->tail = prev_node;
            list->size--;
            free(node);
            return EXIT_SUCCESS;
        }
        prev_node->next = node->next;
        list->size--;
        free(node);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int list_size(struct LinkedList* list) {
    assert(list);
    return list->size;
}

bool list_isEmpty(struct LinkedList* list) {
    assert(list);
    return (!list->size)?1:0;
}

void list_display(struct LinkedList* list) {
    assert(list);
    struct Node* node = list->head;
    while(node) {
        printf("%c", node->data);
        node = node->next;
        if(node) {
            printf("->");
        }
    }
    printf("\n");
}