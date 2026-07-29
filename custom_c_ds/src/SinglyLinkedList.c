#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

/* 
 * Helper function to create a new node.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
static SinglyNode* createNode(int data) {
    SinglyNode* newNode = (SinglyNode*)malloc(sizeof(SinglyNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* 
 * Initializes an empty list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
SinglyLinkedList* createSLL() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

/* 
 * Inserts a new node at the beginning of the list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void insertFrontSLL(SinglyLinkedList* list, int data) {
    if (!list) return;
    SinglyNode* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

/* 
 * Inserts a new node at the end of the list.
 * Time Complexity: O(N) where N is the number of nodes
 * Space Complexity: O(1)
 */
void insertBackSLL(SinglyLinkedList* list, int data) {
    if (!list) return;
    SinglyNode* newNode = createNode(data);
    
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    
    SinglyNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/* 
 * Deletes the first occurrence of a specific value.
 * Time Complexity: O(N) in the worst case
 * Space Complexity: O(1)
 */
bool deleteValueSLL(SinglyLinkedList* list, int data) {
    if (!list || !list->head) return false;
    
    SinglyNode* current = list->head;
    SinglyNode* prev = NULL;
    
    // If the node to be deleted is the head
    if (current != NULL && current->data == data) {
        list->head = current->next;
        free(current);
        return true;
    }
    
    // Search for the node, keeping track of the previous node
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    
    // If the value was not present
    if (current == NULL) return false;
    
    // Unlink the node and free memory
    prev->next = current->next;
    free(current);
    return true;
}

/* 
 * Searches for a value in the list.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool searchSLL(SinglyLinkedList* list, int data) {
    if (!list) return false;
    SinglyNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
}

/* 
 * Prints the entire list.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void printSLL(SinglyLinkedList* list) {
    if (!list) return;
    SinglyNode* current = list->head;
    printf("SLL: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* 
 * Frees all nodes in the list and the list wrapper itself.
 * Crucial for preventing memory leaks (Valgrind will test this).
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void freeSLL(SinglyLinkedList* list) {
    if (!list) return;
    SinglyNode* current = list->head;
    SinglyNode* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}