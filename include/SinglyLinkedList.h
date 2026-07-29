#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>

// PascalCase for structs
typedef struct SinglyNode {
    int data;
    struct SinglyNode* next;
} SinglyNode;

typedef struct SinglyLinkedList {
    SinglyNode* head;
} SinglyLinkedList;

// camelCase for functions
SinglyLinkedList* createSLL();
void insertFrontSLL(SinglyLinkedList* list, int data);
void insertBackSLL(SinglyLinkedList* list, int data);
bool deleteValueSLL(SinglyLinkedList* list, int data);
bool searchSLL(SinglyLinkedList* list, int data);
void printSLL(SinglyLinkedList* list);
void freeSLL(SinglyLinkedList* list);

#endif // SINGLY_LINKED_LIST_H