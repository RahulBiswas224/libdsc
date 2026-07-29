#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>

// PascalCase for structs
typedef struct QueueArray {
    int capacity;
    int front;
    int rear;
    int size;
    int* array;
} QueueArray;

// camelCase for functions
QueueArray* createQueueArray(int capacity);
bool enqueueQA(QueueArray* queue, int data);
bool dequeueQA(QueueArray* queue, int* outData);
bool peekQA(QueueArray* queue, int* outData);
bool isEmptyQA(QueueArray* queue);
bool isFullQA(QueueArray* queue);
void printQA(QueueArray* queue);
void freeQueueArray(QueueArray* queue);

#endif // QUEUE_ARRAY_H