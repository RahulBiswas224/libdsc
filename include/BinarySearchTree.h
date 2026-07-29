#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

// PascalCase for structs
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinarySearchTree {
    TreeNode* root;
} BinarySearchTree;

// camelCase for functions
BinarySearchTree* createBST();
void insertBST(BinarySearchTree* tree, int data);
bool deleteValueBST(BinarySearchTree* tree, int data);
bool searchBST(BinarySearchTree* tree, int data);

// Traversals
void inorderBST(BinarySearchTree* tree);
void preorderBST(BinarySearchTree* tree);
void postorderBST(BinarySearchTree* tree);

// Memory Management
void freeBST(BinarySearchTree* tree);

#endif // BINARY_SEARCH_TREE_H