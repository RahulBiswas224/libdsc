#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

// PascalCase for structs
typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    int size;       // Number of buckets
    int count;      // Number of elements in the table
    HashNode** buckets; // Array of pointers to HashNodes
} HashTable;

// camelCase for functions
HashTable* createHashTable(int size);
void insertHT(HashTable* ht, const char* key, int value);
bool searchHT(HashTable* ht, const char* key, int* outValue);
bool deleteHT(HashTable* ht, const char* key);
void printHT(HashTable* ht);
void freeHashTable(HashTable* ht);

#endif // HASH_TABLE_H