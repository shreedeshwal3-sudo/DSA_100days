/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
bool isCBT(struct Node* root, int index, int totalNodes) {
    if (root == NULL) return true;

    if (index >= totalNodes) return false;

    return isCBT(root->left, 2 * index + 1, totalNodes) &&
           isCBT(root->right, 2 * index + 2, totalNodes);
}

// Check Min Heap property
bool isMinHeap(struct Node* root) {
    if (root == NULL) return true;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // Both children
    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

// Main function
bool isHeap(struct Node* root) {
    int totalNodes = countNodes(root);
    return isCBT(root, 0, totalNodes) && isMinHeap(root);
}