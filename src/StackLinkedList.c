#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

/* 
 * Initializes an empty Linked List stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
StackLinkedList* createStackLinkedList() {
    StackLinkedList* stack = (StackLinkedList*)malloc(sizeof(StackLinkedList));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

/* 
 * Checks if the stack is empty.
 * Time Complexity: O(1)
 */
bool isEmptySLLStack(StackLinkedList* stack) {
    return stack == NULL || stack->top == NULL;
}

/* 
 * Pushes an element onto the top of the stack (head of the list).
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void pushSLLStack(StackLinkedList* stack, int data) {
    if (!stack) return;
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

/* 
 * Pops an element from the top of the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool popSLLStack(StackLinkedList* stack, int* outData) {
    if (isEmptySLLStack(stack)) return false;
    
    StackNode* temp = stack->top;
    if (outData) {
        *outData = temp->data;
    }
    stack->top = stack->top->next;
    free(temp);
    
    return true;
}

/* 
 * Peeks at the top element without removing it.
 * Time Complexity: O(1)
 */
bool peekSLLStack(StackLinkedList* stack, int* outData) {
    if (isEmptySLLStack(stack)) return false;
    
    if (outData) {
        *outData = stack->top->data;
    }
    return true;
}

/* 
 * Prints the stack from top to bottom.
 * Time Complexity: O(N)
 */
void printSLLStack(StackLinkedList* stack) {
    if (isEmptySLLStack(stack)) {
        printf("Stack (Linked List) is empty.\n");
        return;
    }
    StackNode* current = stack->top;
    printf("Stack (Linked List) Top -> Bottom: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* 
 * Frees all nodes in the stack.
 * Time Complexity: O(N)
 */
void freeStackLinkedList(StackLinkedList* stack) {
    if (!stack) return;
    StackNode* current = stack->top;
    StackNode* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(stack);
}