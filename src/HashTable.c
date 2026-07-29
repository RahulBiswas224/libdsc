#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

/* 
 * Internal hash function to convert a string key into a bucket index.
 * Uses a simple polynomial rolling hash.
 * Time Complexity: O(K) where K is the length of the string key
 */
static unsigned int hashFunction(HashTable* ht, const char* key) {
    unsigned long int hashValue = 0;
    unsigned int i = 0;
    unsigned int keyLen = strlen(key);
    
    for (; i < keyLen; ++i) {
        hashValue = hashValue * 37 + key[i];
    }
    
    return hashValue % ht->size;
}

/* 
 * Initializes a hash table with a fixed number of buckets.
 * Time Complexity: O(M) where M is the size of the table
 * Space Complexity: O(M) for the bucket array
 */
HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (!ht) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    ht->size = size;
    ht->count = 0;
    
    // calloc initializes all bucket pointers to NULL
    ht->buckets = (HashNode**)calloc(ht->size, sizeof(HashNode*));
    if (!ht->buckets) {
        fprintf(stderr, "Memory allocation failed for buckets\n");
        free(ht);
        exit(EXIT_FAILURE);
    }
    
    return ht;
}

/* 
 * Inserts a key-value pair. If key exists, updates the value.
 * Time Complexity: Average O(1), Worst Case O(N) where N is chain length
 * Space Complexity: O(K) to store the copy of the string key
 */
void insertHT(HashTable* ht, const char* key, int value) {
    if (!ht || !key) return;
    
    unsigned int slot = hashFunction(ht, key);
    HashNode* current = ht->buckets[slot];
    
    // Check if key already exists, update value if it does
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    
    // Key not found, create new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Deep copy the key to prevent external memory issues
    newNode->key = (char*)malloc(strlen(key) + 1);
    strcpy(newNode->key, key);
    newNode->value = value;
    
    // Insert at the head of the linked list for this bucket
    newNode->next = ht->buckets[slot];
    ht->buckets[slot] = newNode;
    ht->count++;
}

/* 
 * Searches for a key and retrieves its value.
 * Time Complexity: Average O(1), Worst Case O(N)
 */
bool searchHT(HashTable* ht, const char* key, int* outValue) {
    if (!ht || !key) return false;
    
    unsigned int slot = hashFunction(ht, key);
    HashNode* current = ht->buckets[slot];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (outValue) *outValue = current->value;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

/* 
 * Deletes a key-value pair from the table.
 * Time Complexity: Average O(1), Worst Case O(N)
 */
bool deleteHT(HashTable* ht, const char* key) {
    if (!ht || !key) return false;
    
    unsigned int slot = hashFunction(ht, key);
    HashNode* current = ht->buckets[slot];
    HashNode* prev = NULL;
    
    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }
    
    // Key not found
    if (current == NULL) return false;
    
    // Unlink the node
    if (prev == NULL) {
        // Node to delete is the head of the chain
        ht->buckets[slot] = current->next;
    } else {
        prev->next = current->next;
    }
    
    // Free the dynamically allocated key and the node
    free(current->key);
    free(current);
    ht->count--;
    
    return true;
}

/* 
 * Prints the hash table structure (useful for visual verification).
 * Time Complexity: O(M + N) where M is buckets and N is total elements
 */
void printHT(HashTable* ht) {
    if (!ht) return;
    printf("Hash Table (Size: %d, Elements: %d):\n", ht->size, ht->count);
    
    for (int i = 0; i < ht->size; i++) {
        printf("Bucket [%d]: ", i);
        HashNode* current = ht->buckets[i];
        if (current == NULL) {
            printf("NULL\n");
        } else {
            while (current != NULL) {
                printf("{%s: %d} -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

/* 
 * Frees the entire hash table.
 * Time Complexity: O(M + N)
 */
void freeHashTable(HashTable* ht) {
    if (!ht) return;
    
    for (int i = 0; i < ht->size; i++) {
        HashNode* current = ht->buckets[i];
        HashNode* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            // Free the string we malloc'd in insertHT
            free(current->key);
            // Free the node itself
            free(current);
            current = nextNode;
        }
    }
    
    // Free the array of bucket pointers
    free(ht->buckets);
    // Free the hash table wrapper
    free(ht);
}