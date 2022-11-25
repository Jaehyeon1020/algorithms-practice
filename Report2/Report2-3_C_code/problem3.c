#include <stdio.h>
#include <stdlib.h>

typedef enum { red, black } Color;

typedef struct node {
    struct node * parent;
    struct node * left;
    struct node * right;
    int data;
    Color color;
} Node;

typedef struct {
    Node * root;
    Node * nil;
} RbTree;

Node * getNewNode(int data) {
    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    newNode->color = red;

    return newNode;
}

RbTree * getNewRBTree() {
    RbTree * tree = (RbTree*)malloc(sizeof(RbTree));
    Node * nil = (Node*)malloc(sizeof(Node));

    nil->parent = NULL;
    nil->left = NULL;
    nil->right = NULL;
    nil->data = 0;
    nil->color = black;
    
    tree->root = nil;
    tree->root = tree->nil;

    return tree;
}

void leftRotation(RbTree * tree, Node * x) {
    Node * y = x->right;
    x->right = y->left;

    if(y->left != tree->nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == tree->nil) {
        tree->root = y;
    }
    else if(x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotation(RbTree * tree, Node * x) {
    Node * y = x->left;
    x->left = y->right;

    if(y->right != tree->nil) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == tree->nil) {
        tree->root = y;
    }
    else if(x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void insertionFix(RbTree * tree, Node * insertedNode) {
    while(insertedNode->parent->color == red) {
        if(insertedNode->parent == insertedNode->parent->parent->left) {
            Node * y = insertedNode->parent->parent->right;

            if(y->color == red) {
                insertedNode->parent->color = black;
                y->color = black;
                insertedNode->parent->parent->color = red;
                insertedNode = insertedNode->parent->parent;
            }
            else {
                if(insertedNode == insertedNode->parent->right) {
                    insertedNode = insertedNode->parent;
                    leftRotation(tree, insertedNode);
                }

                insertedNode->parent->color = black;
                insertedNode->parent->parent->color = red;
                rightRotation(tree, insertedNode->parent->parent);
            }
        }
        else {
            Node * y = insertedNode->parent->parent->left;

            if(y->color == red) {
                insertedNode->parent->color = black;
                y->color = black;
                insertedNode->parent->parent->color = red;
                insertedNode = insertedNode->parent->parent;
            }
            else {
                if(insertedNode == insertedNode->parent->left) {
                    insertedNode = insertedNode->parent;
                    rightRotation(tree, insertedNode);
                }

                insertedNode->parent->color = black;
                insertedNode->parent->parent->color = 1;
                leftRotation(tree, insertedNode->parent->parent);
            }
        }
    }

    tree->root->color = black;
}

void RB_INSERT(RbTree * T, int k) {
    Node * insertNode = getNewNode(k);

    Node * y = T->nil;
    Node * temp = T->root;

    while(temp != T->nil) {
        y = temp;

        if(insertNode->data < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    insertNode->parent = y;

    if(y == T->nil) {
        T->root = insertNode;
    }
    else if(insertNode->data < y->data) {
        y->left = insertNode;
    }
    else {
        y->right = insertNode;
    }

    insertNode->left = T->nil;
    insertNode->right = T->nil;
    insertNode->color = red;

    insertionFix(T, insertNode);
}

void deletionFix(RbTree * tree, Node * deleteNode) {
    Node * y;

    while(deleteNode != tree->nil && deleteNode != tree->root && deleteNode->color == black) {
        if(deleteNode == deleteNode->parent->left) {
            y = deleteNode->parent->right;

            if(y->color == red) {
                y->color = black;
                deleteNode->parent->color = red;
                leftRotation(tree, deleteNode->parent);
                y = deleteNode->parent->right;
            }

            if(y->left->color == black && y->right->color == black) {
                y->color = red;
                deleteNode = deleteNode->parent;
            }
            else {
                if(y->right->color == black) {
                    y->left->color = black;
                    y->color = red;
                    rightRotation(tree, y);
                    y = deleteNode->parent->right;
                }

                y->color = deleteNode->parent->color;
                deleteNode->parent->color = black;
                y->right->color = black;
                leftRotation(tree, deleteNode->parent);
                deleteNode = tree->root;
            }
        }
        else {
            y = deleteNode->parent->right;

            if(y->color == red) {
                y->color = black;
                deleteNode->parent->color = red;
                leftRotation(tree, deleteNode->parent);
                y = deleteNode->parent->right;
            }

            if(y->left->color == black && y->right->color == black) {
                y->color = red;
                deleteNode = deleteNode->parent;
            }
            else {
                if(y->right->color == black) {
                    y->left->color = black;
                    y->color = red;
                    rightRotation(tree, deleteNode);
                    y = deleteNode->parent->right;
                }

                y->color = deleteNode->parent->color;
                deleteNode->parent->color = black;
                y->right->color = black;
                leftRotation(tree, deleteNode->parent);
                deleteNode = tree->root;
            }
        }

        deleteNode->color = black;
    }
}

Node * findKey(Node * root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }

    if(root->data < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

Node * getMinValue(Node * node) {
    Node * cur = node;

    while(cur->left != NULL) {
        cur = cur->left;
    }
    
    return cur;
}

Node * getSuccessor(Node * root) {
    if(root->right != NULL) {
        return getMinValue(root->right);
    }

    Node * p = root->parent;
    while(p != NULL && root == p->right) {
        root = p;
        p = p->parent;
    }

    return p;
}

void RB_DELETE(RbTree * T, int k) {
    Node * x;
    Node * y;
    Node * z = findKey(T->root, k);

    if((z->left == T->nil) || (z->right == T->nil)) {
        y = z;
    }
    else {
        y = getSuccessor(z);
    }

    if(y->left != T->nil) {
        x = y->left;
    }
    else {
        x = y->right;
    }

    x->parent = y->parent;

    if(y->parent == T->nil) {
        T->root = x;
    }
    else if(y = y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }

    if(y != z) {
        z->data = y->data;
    }

    if(y->color == black) {
        deletionFix(T, x);
    }
}

int main() {
    

    return 0;
}