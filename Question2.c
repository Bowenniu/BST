#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of a TreeNode struct for binary tree nodes.
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Create new node with given value
struct TreeNode* createNode(int value) {
    // Allocate memory for new node, tell the user if failed.
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize the node's value and child pointers
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
// Insert Node into binary tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) { // if tree is empty, create new node as root
        root = createNode(value);
    } else if (value < root -> value) { 
        root -> left = insertNode(root -> left, value); // intert value into the left subtree
    } else if (value > root -> value) {
        root -> right = insertNode(root -> right, value); // insert value into the right subtree
    }
    return root;
}
// Function to check if this is binary tree
int isBSTUtil(struct TreeNode* node, int min, int max) {
    if (node == NULL) return 1;
    if (node -> value <= min || node -> value >= max) return 0;
    // check the left and right subtrees
    return isBSTUtil (node -> left, min, node -> value) && 
        isBSTUtil (node -> right, node -> value, max);
}
// Function to check if the binary tree is a BST
int isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void printfTree(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root -> value);
    printfTree(root -> left);
    printfTree(root -> right);
}
// make up test 
int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);

    if (isBST(root)) {
        printf("The tree is a BST.\n");
    } else {
        printf("The tree is not a BST.\n");
    }
    return 0;
}

/*
The program starts by defining a TreeNode structure to represent each node in the tree. Each node contains an integer value, 
as well as two pointers that point to its left child node and right child node. Through the createNode function, 
a new node can be created and initialized with a specified value, while its child pointers are set to NULL initially. 
The TreeNode structure encapsulates the basic components of a node in a binary tree: an integer value and pointers to its left and 
right child nodes. The createNode function allows the creation of new TreeNode instances, initializing their values and ensuring their 
child pointers are initially null, ready for subsequent tree construction.
*/