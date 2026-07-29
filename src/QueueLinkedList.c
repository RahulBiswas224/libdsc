#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

/* 
 * Initializes an empty Linked List queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
QueueLinkedList* createQueueLinkedList() {
    QueueLinkedList* queue = (QueueLinkedList*)malloc(sizeof(QueueLinkedList));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/* 
 * Checks if the queue is empty.
 * Time Complexity: O(1)
 */
bool isEmptyQLL(QueueLinkedList* queue) {
    return queue == NULL || queue->front == NULL;
}

/* 
 * Enqueues an element at the rear of the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void enqueueQLL(QueueLinkedList* queue, int data) {
    if (!queue) return;
    
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    
    // If queue is empty, then new node is both front and rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    // Add the new node at the end of the queue and change rear
    queue->rear->next = newNode;
    queue->rear = newNode;
}

/* 
 * Dequeues an element from the front of the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool dequeueQLL(QueueLinkedList* queue, int* outData) {
    if (isEmptyQLL(queue)) return false;
    
    QueueNode* temp = queue->front;
    if (outData) {
        *outData = temp->data;
    }
    
    queue->front = queue->front->next;
    
    // If front becomes NULL, then rear also becomes NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return true;
}

/* 
 * Peeks at the front element without removing it.
 * Time Complexity: O(1)
 */
bool peekQLL(QueueLinkedList* queue, int* outData) {
    if (isEmptyQLL(queue)) return false;
    
    if (outData) {
        *outData = queue->front->data;
    }
    return true;
}

/* 
 * Prints the queue from front to rear.
 * Time Complexity: O(N)
 */
void printQLL(QueueLinkedList* queue) {
    if (isEmptyQLL(queue)) {
        printf("Queue (Linked List) is empty.\n");
        return;
    }
    QueueNode* current = queue->front;
    printf("Queue (Linked List) Front -> Rear: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* 
 * Frees all nodes in the queue.
 * Time Complexity: O(N)
 */
void freeQueueLinkedList(QueueLinkedList* queue) {
    if (!queue) return;
    QueueNode* current = queue->front;
    QueueNode* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(queue);
}