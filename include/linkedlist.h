#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>

typedef struct Node Node_t;
typedef struct LinkedList LinkedList_t;

/**
 * @brief Create a List object
 *
 * @return struct LinkedList*
 */
struct LinkedList* createList();

/**
 * @brief Destroy a List object
 *
 * @param list
 */
void destroyList(struct LinkedList* list);

/**
 * @brief Inster new node to the list
 *
 * @param list
 * @param data
 */
void list_insert(struct LinkedList* list, char data);

/**
 * @brief Delete list node
 *
 * @param list
 * @param data
 * @return EXIT_SUCCESS on success, EXIT_FAILURE othewise
 */
int list_delete(struct LinkedList* list, char data);

/**
 * @brief List size
 *
 * @param list
 * @return list size
 */
int list_size(struct LinkedList* list);

/**
 * @brief Check whether list is empty
 *
 * @param list
 * @return true
 * @return true if list is empty
 */
bool list_isEmpty(struct LinkedList* list);

/**
 * @brief Display the list
 *
 * @param list
 */
void list_display(struct LinkedList* list);

#endif