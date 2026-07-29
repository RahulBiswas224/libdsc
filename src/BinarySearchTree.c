#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

/* --- Internal Recursive Helper Functions --- */

static TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

static TreeNode* insertRecursive(TreeNode* node, int data) {
    if (node == NULL) {
        return createTreeNode(data);
    }
    if (data < node->data) {
        node->left = insertRecursive(node->left, data);
    } else if (data > node->data) {
        node->right = insertRecursive(node->right, data);
    }
    // If data == node->data, we ignore duplicates
    return node;
}

static bool searchRecursive(TreeNode* node, int data) {
    if (node == NULL) return false;
    if (node->data == data) return true;
    
    if (data < node->data) {
        return searchRecursive(node->left, data);
    } else {
        return searchRecursive(node->right, data);
    }
}

static TreeNode* findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

static TreeNode* deleteRecursive(TreeNode* node, int data, bool* wasDeleted) {
    if (node == NULL) return NULL;

    if (data < node->data) {
        node->left = deleteRecursive(node->left, data, wasDeleted);
    } else if (data > node->data) {
        node->right = deleteRecursive(node->right, data, wasDeleted);
    } else {
        // Node found!
        *wasDeleted = true;

        // Case 1: No child or 1 child
        if (node->left == NULL) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        // Case 2: Two children
        // Find the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(node->right);
        // Copy the inorder successor's content to this node
        node->data = temp->data;
        // Delete the inorder successor
        node->right = deleteRecursive(node->right, temp->data, wasDeleted);
    }
    return node;
}

static void inorderRecursive(TreeNode* node) {
    if (node != NULL) {
        inorderRecursive(node->left);
        printf("%d ", node->data);
        inorderRecursive(node->right);
    }
}

static void preorderRecursive(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

static void postorderRecursive(TreeNode* node) {
    if (node != NULL) {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        printf("%d ", node->data);
    }
}

static void freeRecursive(TreeNode* node) {
    if (node != NULL) {
        // Must use post-order traversal to free children before parent!
        freeRecursive(node->left);
        freeRecursive(node->right);
        free(node);
    }
}

/* --- Public API --- */

/* Time/Space: O(1) */
BinarySearchTree* createBST() {
    BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (!tree) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

/* 
 * Time Complexity: O(H) where H is tree height. O(log N) average, O(N) worst case.
 * Space Complexity: O(H) due to recursive call stack.
 */
void insertBST(BinarySearchTree* tree, int data) {
    if (tree) {
        tree->root = insertRecursive(tree->root, data);
    }
}

/* 
 * Time Complexity: O(H)
 * Space Complexity: O(H) 
 */
bool searchBST(BinarySearchTree* tree, int data) {
    if (!tree) return false;
    return searchRecursive(tree->root, data);
}

/* 
 * Time Complexity: O(H)
 * Space Complexity: O(H)
 */
bool deleteValueBST(BinarySearchTree* tree, int data) {
    if (!tree) return false;
    bool wasDeleted = false;
    tree->root = deleteRecursive(tree->root, data, &wasDeleted);
    return wasDeleted;
}

/* Time: O(N), Space: O(H) */
void inorderBST(BinarySearchTree* tree) {
    if (!tree || !tree->root) {
        printf("BST is empty\n");
        return;
    }
    printf("Inorder: ");
    inorderRecursive(tree->root);
    printf("\n");
}

/* Time: O(N), Space: O(H) */
void preorderBST(BinarySearchTree* tree) {
    if (!tree || !tree->root) return;
    printf("Preorder: ");
    preorderRecursive(tree->root);
    printf("\n");
}

/* Time: O(N), Space: O(H) */
void postorderBST(BinarySearchTree* tree) {
    if (!tree || !tree->root) return;
    printf("Postorder: ");
    postorderRecursive(tree->root);
    printf("\n");
}

/* Time: O(N), Space: O(H) */
void freeBST(BinarySearchTree* tree) {
    if (tree) {
        freeRecursive(tree->root);
        free(tree);
    }
}