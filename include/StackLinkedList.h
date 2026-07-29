#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>

// PascalCase for structs
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct StackLinkedList {
    StackNode* top;
} StackLinkedList;

// camelCase for functions
StackLinkedList* createStackLinkedList();
void pushSLLStack(StackLinkedList* stack, int data);
bool popSLLStack(StackLinkedList* stack, int* outData);
bool peekSLLStack(StackLinkedList* stack, int* outData);
bool isEmptySLLStack(StackLinkedList* stack);
void printSLLStack(StackLinkedList* stack);
void freeStackLinkedList(StackLinkedList* stack);

#endif // STACK_LINKED_LIST_H