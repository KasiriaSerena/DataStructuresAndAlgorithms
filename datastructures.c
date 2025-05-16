#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

int getNodeCount(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getNodeCount(root->leftChild) + getNodeCount(root->rightChild);
}

void compareTrees(struct Node* treeA, struct Node* treeB, struct Node* treeC) {
    int countA = getNodeCount(treeA);
    int countB = getNodeCount(treeB);
    int countC = getNodeCount(treeC);

    printf("Node counts:\n");
    printf("Tree A: %d nodes\n", countA);
    printf("Tree B: %d nodes\n", countB);
    printf("Tree C: %d nodes\n", countC);

    if (countA >= countB && countA >= countC) {
        printf("Tree A has the highest number of nodes.\n");
    } else if (countB >= countA && countB >= countC) {
        printf("Tree B has the highest number of nodes.\n");
    } else {
        printf("Tree C has the highest number of nodes.\n");
    }
}

int main() {
    struct Node* treeA = createNode(1);
    treeA->leftChild = createNode(2);
    treeA->rightChild = createNode(3);

    struct Node* treeB = createNode(4);
    treeB->leftChild = createNode(5);
    treeB->rightChild = createNode(6);
    treeB->leftChild->leftChild = createNode(7);
    treeB->leftChild->rightChild = createNode(8);

    struct Node* treeC = createNode(9);
    treeC->leftChild = createNode(10);
    treeC->rightChild = createNode(11);
    treeC->rightChild->leftChild = createNode(12);

    compareTrees(treeA, treeB, treeC);

    return 0;
}
