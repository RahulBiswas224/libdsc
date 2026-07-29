#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

/* 
 * Initializes a circular array queue.
 * Time Complexity: O(1)
 * Space Complexity: O(N) where N is the capacity
 */
QueueArray* createQueueArray(int capacity) {
    QueueArray* queue = (QueueArray*)malloc(sizeof(QueueArray));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1; // Allows first enqueue to wrap to index 0
    
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        fprintf(stderr, "Memory allocation failed for queue array\n");
        free(queue);
        exit(EXIT_FAILURE);
    }
    return queue;
}

/* 
 * Checks if the queue is empty.
 * Time Complexity: O(1)
 */
bool isEmptyQA(QueueArray* queue) {
    return queue == NULL || queue->size == 0;
}

/* 
 * Checks if the queue is full.
 * Time Complexity: O(1)
 */
bool isFullQA(QueueArray* queue) {
    return queue != NULL && queue->size == queue->capacity;
}

/* 
 * Enqueues an element at the rear of the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool enqueueQA(QueueArray* queue, int data) {
    if (isFullQA(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", data);
        return false;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size++;
    return true;
}

/* 
 * Dequeues an element from the front of the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool dequeueQA(QueueArray* queue, int* outData) {
    if (isEmptyQA(queue)) return false;
    if (outData) {
        *outData = queue->array[queue->front];
    }
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return true;
}

/* 
 * Peeks at the front element without removing it.
 * Time Complexity: O(1)
 */
bool peekQA(QueueArray* queue, int* outData) {
    if (isEmptyQA(queue)) return false;
    if (outData) {
        *outData = queue->array[queue->front];
    }
    return true;
}

/* 
 * Prints the circular queue from front to rear.
 * Time Complexity: O(N)
 */
void printQA(QueueArray* queue) {
    if (isEmptyQA(queue)) {
        printf("Queue (Array) is empty.\n");
        return;
    }
    printf("Queue (Array) Front -> Rear: ");
    int count = 0;
    int index = queue->front;
    while (count < queue->size) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
        count++;
    }
    printf("\n");
}

/* 
 * Frees the dynamically allocated array and the queue structure.
 * Time Complexity: O(1)
 */
void freeQueueArray(QueueArray* queue) {
    if (!queue) return;
    free(queue->array);
    free(queue);
}