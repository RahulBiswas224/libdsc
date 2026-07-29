#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

// PascalCase for structs
typedef struct StackArray {
    int capacity;
    int top;
    int* array;
} StackArray;

// camelCase for functions
StackArray* createStackArray(int capacity);
bool pushSA(StackArray* stack, int data);
bool popSA(StackArray* stack, int* outData);
bool peekSA(StackArray* stack, int* outData);
bool isEmptySA(StackArray* stack);
bool isFullSA(StackArray* stack);
void printSA(StackArray* stack);
void freeStackArray(StackArray* stack);

#endif // STACK_ARRAY_H