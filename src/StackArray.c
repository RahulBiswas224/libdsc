#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* 
 * Initializes a stack with a fixed capacity.
 * Time Complexity: O(1)
 * Space Complexity: O(N) where N is the capacity
 */
StackArray* createStackArray(int capacity) {
    StackArray* stack = (StackArray*)malloc(sizeof(StackArray));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1; // -1 indicates an empty stack
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        fprintf(stderr, "Memory allocation failed for stack array\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    return stack;
}

/* 
 * Checks if the stack is empty.
 * Time Complexity: O(1)
 */
bool isEmptySA(StackArray* stack) {
    return stack == NULL || stack->top == -1;
}

/* 
 * Checks if the stack is full.
 * Time Complexity: O(1)
 */
bool isFullSA(StackArray* stack) {
    return stack != NULL && stack->top == stack->capacity - 1;
}

/* 
 * Pushes an element onto the top of the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool pushSA(StackArray* stack, int data) {
    if (isFullSA(stack)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return false;
    }
    stack->array[++stack->top] = data;
    return true;
}

/* 
 * Pops an element from the top of the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
bool popSA(StackArray* stack, int* outData) {
    if (isEmptySA(stack)) return false;
    if (outData) {
        *outData = stack->array[stack->top];
    }
    stack->top--;
    return true;
}

/* 
 * Peeks at the top element without removing it.
 * Time Complexity: O(1)
 */
bool peekSA(StackArray* stack, int* outData) {
    if (isEmptySA(stack)) return false;
    if (outData) {
        *outData = stack->array[stack->top];
    }
    return true;
}

/* 
 * Prints the stack from top to bottom.
 * Time Complexity: O(N)
 */
void printSA(StackArray* stack) {
    if (isEmptySA(stack)) {
        printf("Stack (Array) is empty.\n");
        return;
    }
    printf("Stack (Array) Top -> Bottom: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

/* 
 * Frees the dynamically allocated array and the stack structure.
 * Time Complexity: O(1)
 */
void freeStackArray(StackArray* stack) {
    if (!stack) return;
    free(stack->array);
    free(stack);
}