#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

struct Node {
    struct Node* prev;
    struct Node* next;
    void* data;
};

struct BinaryTree {
    struct Node* head;
    struct Node* tail;
};

/**
 * @brief Insert a new node into the tree
 *
 * @param queue
 * @param node
 */
void insert(struct BinaryTree* tree, struct Node* node);

/**
 * @brief Delete a node
 *
 * @param queue
 * @return struct Node*
 */
struct Node* deleteNode(struct BinaryTree* tree);

/**
 * @brief Search for a node in the tree
 *
 * @param queue
 * @return struct Node*
 */
struct Node* search(struct BinaryTree* tree);

/**
 * @brief return the number of elements in the tree
 *
 * @return int
 */
int size(struct BinaryTree* tree);

#endif // _BINARY_TREE