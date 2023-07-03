#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure representing the seller information
typedef struct Seller {
    float price;
    char origin[50];
} Seller;

// Structure representing the stock information
typedef struct Stock {
    int quantity;
    int location;
} Stock;

// Structure representing a B-tree node
typedef struct BTreeNode {
    char** keys;
    struct Seller* sellers;
    struct Stock* stocks;
    struct BTreeNode** children;
    int num_keys;
    bool is_leaf;
} BTreeNode;

// Function to create a new B-tree node
BTreeNode* createNode(bool is_leaf, int degree) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->keys = (char**)malloc((degree - 1) * sizeof(char*));
    newNode->sellers = (Seller*)malloc((degree - 1) * sizeof(Seller));
    newNode->stocks = (Stock*)malloc((degree - 1) * sizeof(Stock));
    newNode->children = (BTreeNode**)malloc(degree * sizeof(BTreeNode*));
    newNode->num_keys = 0;
    newNode->is_leaf = is_leaf;
    return newNode;
}

// Function to search a key in the B-tree
int searchKey(char* key, char** keys, int num_keys) {
    int idx = 0;
    while (idx < num_keys && strcmp(key, keys[idx]) > 0)
        idx++;
    return idx;
}

// Function to split the child node
void splitChild(BTreeNode* parentNode, int childIndex, int degree) {
    BTreeNode* childNode = parentNode->children[childIndex];
    BTreeNode* newNode = createNode(childNode->is_leaf, degree);
    newNode->num_keys = degree - 1;

    for (int i = 0; i < degree - 1; i++) {
        newNode->keys[i] = childNode->keys[i + degree];
        newNode->sellers[i] = childNode->sellers[i + degree];
        newNode->stocks[i] = childNode->stocks[i + degree];
    }

    if (!childNode->is_leaf) {
        for (int i = 0; i < degree; i++)
            newNode->children[i] = childNode->children[i + degree];
    }

    childNode->num_keys = degree - 1;

    for (int i = parentNode->num_keys; i >= childIndex + 1; i--)
        parentNode->children[i + 1] = parentNode->children[i];

    parentNode->children[childIndex + 1] = newNode;

    for (int i = parentNode->num_keys - 1; i >= childIndex; i--) {
        parentNode->keys[i + 1] = parentNode->keys[i];
        parentNode->sellers[i + 1] = parentNode->sellers[i];
        parentNode->stocks[i + 1] = parentNode->stocks[i];
    }

    parentNode->keys[childIndex] = childNode->keys[degree - 1];
    parentNode->sellers[childIndex] = childNode->sellers[degree - 1];
    parentNode->stocks[childIndex] = childNode->stocks[degree - 1];
    parentNode->num_keys++;
}

// Function to remove a key from the B-tree
BTreeNode* removeKey(BTreeNode* root, char* key, int degree) {
    if (!root)
        return root;

    int idx = searchKey(key, root->keys, root->num_keys);

    if (idx < root->num_keys && strcmp(key, root->keys[idx]) == 0) {
        if (root->is_leaf) {
            free(root->keys[idx]);
            for (int i = idx + 1; i < root->num_keys; i++) {
                root->keys[i - 1] = root->keys[i];
                root->sellers[i - 1] = root->sellers[i];
                root->stocks[i - 1] = root->stocks[i];
            }
            root->num_keys--;
            return root;
        }

        if (root->children[idx]->num_keys >= degree) {
            char* predecessor = root->children[idx]->keys[root->children[idx]->num_keys - 1];
            root->keys[idx] = strdup(predecessor);
            root->sellers[idx] = root->children[idx]->sellers[root->children[idx]->num_keys - 1];
            root->stocks[idx] = root->children[idx]->stocks[root->children[idx]->num_keys - 1];
            root->children[idx] = removeKey(root->children[idx], predecessor, degree);
            return root;
        }

        if (root->children[idx + 1]->num_keys >= degree) {
            char* successor = root->children[idx + 1]->keys[0];
            root->keys[idx] = strdup(successor);
            root->sellers[idx] = root->children[idx + 1]->sellers[0];
            root->stocks[idx] = root->children[idx + 1]->stocks[0];
            root->children[idx + 1] = removeKey(root->children[idx + 1], successor, degree);
            return root;
        }

        BTreeNode* leftChild = root->children[idx];
        BTreeNode* rightChild = root->children[idx + 1];
        leftChild->keys[degree - 1] = strdup(root->keys[idx]);
        leftChild->sellers[degree - 1] = root->sellers[idx];
        leftChild->stocks[degree - 1] = root->stocks[idx];

        for (int i = 0; i < rightChild->num_keys; i++) {
            leftChild->keys[i + degree] = rightChild->keys[i];
            leftChild->sellers[i + degree] = rightChild->sellers[i];
            leftChild->stocks[i + degree] = rightChild->stocks[i];
        }

        if (!leftChild->is_leaf) {
            for (int i = 0; i <= rightChild->num_keys; i++)
                leftChild->children[i + degree] = rightChild->children[i];
        }

        for (int i = idx + 1; i < root->num_keys; i++) {
            root->keys[i - 1] = root->keys[i];
            root->sellers[i - 1] = root->sellers[i];
            root->stocks[i - 1] = root->stocks[i];
        }

        for (int i = idx + 2; i <= root->num_keys; i++)
            root->children[i - 1] = root->children[i];

        leftChild->num_keys += rightChild->num_keys + 1;
        root->num_keys--;

        free(rightChild->keys);
        free(rightChild->sellers);
        free(rightChild->stocks);
        free(rightChild);

        if (root->num_keys == 0) {
            BTreeNode* tmp = root;
            root = root->children[0];
            free(tmp->keys);
            free(tmp->sellers);
            free(tmp->stocks);
            free(tmp->children);
            free(tmp);
        }

        root = removeKey(root, key, degree);
        return root;
    }

    if (root->is_leaf)
        return root;

    bool isLastChild = (idx == root->num_keys);

    if (root->children[idx]->num_keys < degree)
        root->children[idx] = removeKey(root->children[idx], key, degree);

    if (isLastChild && idx > root->num_keys)
        root->children[idx - 1] = removeKey(root->children[idx - 1], key, degree);
    else
        root->children[idx + 1] = removeKey(root->children[idx + 1], key, degree);

    return root;
}

// Function to remove a key from the B-tree
BTreeNode* remove(BTreeNode* root, char* key, int degree) {
    if (!root) {
        printf("The tree is empty.\n");
        return root;
    }

    root = removeKey(root, key, degree);
    return root;
}

// Function to print the B-tree
void printBTree(BTreeNode* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            printBTree(root->children[i]);
            printf("Key: %s\n", root->keys[i]);
            printf("Seller: Price=%.2f, Origin=%s\n", root->sellers[i].price, root->sellers[i].origin);
            printf("Stock: Quantity=%d, Location=%d\n", root->stocks[i].quantity, root->stocks[i].location);
        }

        printBTree(root->children[root->num_keys]);
    }
}

// Function to free the B-tree nodes
void freeBTree(BTreeNode* root) {
    if (root) {
        if (!root->is_leaf) {
            for (int i = 0; i <= root->num_keys; i++)
                freeBTree(root->children[i]);
        }

        for (int i = 0; i < root->num_keys; i++) {
            free(root->keys[i]);
        }

        free(root->keys);
        free(root->sellers);
        free(root->stocks);
        free(root->children);
        free(root);
    }
}

// Driver code
int main() {
    int degree = 3; // Degree of the B-tree

    BTreeNode* root = createNode(true, degree);

    // Insert keys into the B-tree
    root = insert(root, "apple", 10, 1, 2, 10, "USA");
    root = insert(root, "banana", 15, 3, 4, 20, "Mexico");
    root = insert(root, "cherry", 20, 5, 6, 15, "Canada");
    root = insert(root, "date", 25, 7, 8, 5, "USA");
    root = insert(root, "grape", 30, 9, 10, 12, "Italy");
    root = insert(root, "kiwi", 35, 11, 12, 8, "New Zealand");
    root = insert(root, "mango", 40, 13, 14, 3, "India");
    root = insert(root, "orange", 45, 15, 16, 7, "USA");
    root = insert(root, "pear", 50, 17, 18, 18, "Spain");
    root = insert(root, "watermelon", 55, 19, 20, 9, "USA");

    printf("B-tree before removal:\n");
    printBTree(root);
    printf("\n");

    // Remove a key from the B-tree
    root = remove(root, "cherry", degree);

    printf("B-tree after removal:\n");
    printBTree(root);
    printf("\n");

    // Free the B-tree nodes
    freeBTree(root);

    return 0;
}
