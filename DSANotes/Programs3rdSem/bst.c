#include <stdio.h>
#include <stdlib.h>

// Typedef for TreeNode
typedef struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

// Function to create a new node with given data
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int x) {
    if (root == NULL) {
        return createNode(x);
    }

    if (x < root->data) {
        root->left = insert(root->left, x);
    }
    else {
        root->right = insert(root->right, x);
    }

    return root;
}

// Function to build the tree
TreeNode* buildTree() {
    TreeNode* root= NULL;
    printf("Enter the data: ");
    int value;
    scanf("%d", &value);
    while (value != -1) {
        root = insert(root, value);
        printf("Enter the data: ");
        scanf("%d", &value);
    }
    return root;
}

// Function to search for a value in the BST
int searchRecursive(TreeNode* node, int value) {
    if (node == NULL) {
        return 0;
    }
    if (value == node->data) {
        return 1;
    }
    else if (value < node->data) {
        return searchRecursive(node->left, value);
    }
    else {
        return searchRecursive(node->right, value);
    }
}

// Function for in-order traversal
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to find the node with the minimum value
TreeNode* minNode(TreeNode* root) {
    TreeNode* temp = root;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

// Function to find the node with the maximum value
TreeNode* maxNode(TreeNode* root) {
    TreeNode* temp = root;

    while (temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

// Function to delete a node with a given value
TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == NULL) {
        return root;
    }

    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->left == NULL && root->right != NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        if (root->left != NULL && root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main() {
    TreeNode* root = buildTree(root);
    printf("\n");
    root = insert(root, 4);
   //LevelOrderTraversal(root);
    inOrderTraversal(root);
    root = deleteNode(root, 4);
    printf("\n");
    printf("Inorder: \n");
    inOrderTraversal(root);
    printf("\n");
    printf("PreOrder: \n");
    preOrderTraversal(root);
    printf("\n");
    printf("PostOrder: \n");
    postOrderTraversal(root);

    return 0;
}
