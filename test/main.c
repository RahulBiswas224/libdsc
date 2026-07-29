#include <stdio.h>
#include <stdlib.h>

// Include all our custom data structures
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "StackArray.h"
#include "StackLinkedList.h"
#include "QueueArray.h"
#include "QueueLinkedList.h"
#include "BinarySearchTree.h"
#include "HashTable.h"

void printSeparator(const char* title) {
    printf("\n========================================\n");
    printf("   %s\n", title);
    printf("========================================\n");
}

void testSinglyLinkedList() {
    printSeparator("SINGLY LINKED LIST");
    SinglyLinkedList* list = createSLL();
    
    insertBackSLL(list, 10);
    insertBackSLL(list, 20);
    insertFrontSLL(list, 5);
    printSLL(list);
    
    printf("Searching for 20: %s\n", searchSLL(list, 20) ? "Found" : "Not Found");
    printf("Deleting 10...\n");
    deleteValueSLL(list, 10);
    printSLL(list);
    
    freeSLL(list);
    printf("Freed Singly Linked List.\n");
}

void testDoublyLinkedList() {
    printSeparator("DOUBLY LINKED LIST");
    DoublyLinkedList* list = createDLL();
    
    insertBackDLL(list, 100);
    insertBackDLL(list, 200);
    insertFrontDLL(list, 50);
    printForwardDLL(list);
    printReverseDLL(list);
    
    printf("Deleting 200 (Tail)...\n");
    deleteValueDLL(list, 200);
    printForwardDLL(list);
    
    freeDLL(list);
    printf("Freed Doubly Linked List.\n");
}

void testStack() {
    printSeparator("STACK (ARRAY & LINKED LIST)");
    
    // Array Stack
    StackArray* sa = createStackArray(3);
    pushSA(sa, 1);
    pushSA(sa, 2);
    pushSA(sa, 3);
    printSA(sa);
    
    int val;
    popSA(sa, &val);
    printf("Popped from Array Stack: %d\n", val);
    freeStackArray(sa);
    
    // Linked List Stack
    StackLinkedList* sll = createStackLinkedList();
    pushSLLStack(sll, 10);
    pushSLLStack(sll, 20);
    printSLLStack(sll);
    
    popSLLStack(sll, &val);
    printf("Popped from LL Stack: %d\n", val);
    freeStackLinkedList(sll);
}

void testQueue() {
    printSeparator("QUEUE (ARRAY & LINKED LIST)");
    
    // Circular Array Queue
    QueueArray* qa = createQueueArray(3);
    enqueueQA(qa, 1);
    enqueueQA(qa, 2);
    enqueueQA(qa, 3);
    printQA(qa);
    
    int val;
    dequeueQA(qa, &val);
    printf("Dequeued from Array Queue: %d\n", val);
    enqueueQA(qa, 4); // Demonstrates circular behavior
    printQA(qa);
    freeQueueArray(qa);
    
    // Linked List Queue
    QueueLinkedList* qll = createQueueLinkedList();
    enqueueQLL(qll, 100);
    enqueueQLL(qll, 200);
    printQLL(qll);
    
    dequeueQLL(qll, &val);
    printf("Dequeued from LL Queue: %d\n", val);
    freeQueueLinkedList(qll);
}

void testBST() {
    printSeparator("BINARY SEARCH TREE");
    BinarySearchTree* bst = createBST();
    
    insertBST(bst, 50);
    insertBST(bst, 30);
    insertBST(bst, 70);
    insertBST(bst, 20);
    insertBST(bst, 40);
    insertBST(bst, 60);
    insertBST(bst, 80);
    
    inorderBST(bst);
    preorderBST(bst);
    postorderBST(bst);
    
    printf("Deleting 30 (Node with two children)...\n");
    deleteValueBST(bst, 30);
    inorderBST(bst);
    
    freeBST(bst);
    printf("Freed BST.\n");
}

void testHashTable() {
    printSeparator("HASH TABLE");
    HashTable* ht = createHashTable(5);
    
    insertHT(ht, "Alice", 101);
    insertHT(ht, "Bob", 102);
    insertHT(ht, "Charlie", 103);
    insertHT(ht, "David", 104);
    insertHT(ht, "Eve", 105);
    // Force a collision intentionally if possible by overloading
    insertHT(ht, "Frank", 106); 
    
    printHT(ht);
    
    int val;
    if (searchHT(ht, "Charlie", &val)) {
        printf("Found Charlie: %d\n", val);
    }
    
    printf("Deleting Bob...\n");
    deleteHT(ht, "Bob");
    printHT(ht);
    
    freeHashTable(ht);
    printf("Freed Hash Table.\n");
}

int main() {
    printf("Starting Data Structures Test Harness...\n");
    
    testSinglyLinkedList();
    testDoublyLinkedList();
    testStack();
    testQueue();
    testBST();
    testHashTable();
    
    printf("\nAll tests completed successfully!\n");
    return EXIT_SUCCESS;
}