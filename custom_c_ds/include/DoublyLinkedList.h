#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

// PascalCase for structs
typedef struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
} DoublyNode;

typedef struct DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail; // Tracking tail makes insertBack O(1)
} DoublyLinkedList;

// camelCase for functions
DoublyLinkedList* createDLL();
void insertFrontDLL(DoublyLinkedList* list, int data);
void insertBackDLL(DoublyLinkedList* list, int data);
bool deleteValueDLL(DoublyLinkedList* list, int data);
bool searchDLL(DoublyLinkedList* list, int data);
void printForwardDLL(DoublyLinkedList* list);
void printReverseDLL(DoublyLinkedList* list); // To test the prev pointers
void freeDLL(DoublyLinkedList* list);

#endif // DOUBLY_LINKED_LIST_H