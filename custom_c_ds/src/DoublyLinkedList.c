#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

/* 
 * Helper function to create a new doubly linked node.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
static DoublyNode* createDoublyNode(int data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* 
 * Initializes an empty doubly linked list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
DoublyLinkedList* createDLL() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/* 
 * Inserts a new node at the beginning of the list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void insertFrontDLL(DoublyLinkedList* list, int data) {
    if (!list) return;
    DoublyNode* newNode = createDoublyNode(data);
    
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

/* 
 * Inserts a new node at the end of the list.
 * Time Complexity: O(1) - Thanks to the tail pointer!
 * Space Complexity: O(1)
 */
void insertBackDLL(DoublyLinkedList* list, int data) {
    if (!list) return;
    DoublyNode* newNode = createDoublyNode(data);
    
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

/* 
 * Deletes the first occurrence of a specific value.
 * Time Complexity: O(N) in the worst case
 * Space Complexity: O(1)
 */
bool deleteValueDLL(DoublyLinkedList* list, int data) {
    if (!list || !list->head) return false;
    
    DoublyNode* current = list->head;
    
    // Search for the node
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    
    // If the value was not present
    if (current == NULL) return false;
    
    // If the node to delete is the head
    if (current == list->head) {
        list->head = current->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        } else {
            list->tail = NULL; // List became empty
        }
    } 
    // If the node to delete is the tail
    else if (current == list->tail) {
        list->tail = current->prev;
        list->tail->next = NULL;
    } 
    // Node is in the middle
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    free(current);
    return true;
}

/* 
 * Searches for a value in the list.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool searchDLL(DoublyLinkedList* list, int data) {
    if (!list) return false;
    DoublyNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
}

/* 
 * Prints the list from head to tail.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void printForwardDLL(DoublyLinkedList* list) {
    if (!list) return;
    DoublyNode* current = list->head;
    printf("DLL (Forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* 
 * Prints the list from tail to head (verifies prev pointers).
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void printReverseDLL(DoublyLinkedList* list) {
    if (!list) return;
    DoublyNode* current = list->tail;
    printf("DLL (Reverse): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

/* 
 * Frees all nodes in the list and the list wrapper itself.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void freeDLL(DoublyLinkedList* list) {
    if (!list) return;
    DoublyNode* current = list->head;
    DoublyNode* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}