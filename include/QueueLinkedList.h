#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>

// PascalCase for structs
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct QueueLinkedList {
    QueueNode* front;
    QueueNode* rear;
} QueueLinkedList;

// camelCase for functions
QueueLinkedList* createQueueLinkedList();
void enqueueQLL(QueueLinkedList* queue, int data);
bool dequeueQLL(QueueLinkedList* queue, int* outData);
bool peekQLL(QueueLinkedList* queue, int* outData);
bool isEmptyQLL(QueueLinkedList* queue);
void printQLL(QueueLinkedList* queue);
void freeQueueLinkedList(QueueLinkedList* queue);

#endif // QUEUE_LINKED_LIST_H