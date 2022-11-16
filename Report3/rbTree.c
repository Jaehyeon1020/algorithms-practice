/**
* Functions that implement Red-Black Tree
*/

#include <stdio.h>
#include <stdlib.h>
#include "rbTree.h"

treeNode* newNode(int data) {
    treeNode* n = malloc(sizeof(treeNode));

    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->color = 1;

    return n;
}

rbTree* newRbTree() {
    rbTree* t = malloc(sizeof(rbTree));
    treeNode* nil_node = malloc(sizeof(treeNode));

    nil_node->parent = NULL;
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->data = 0;
    nil_node->color = 0;
    t->NIL = nil_node;
    t->root = t->NIL;

    return t;
}

void leftRotation(rbTree* t, treeNode* x) {
    treeNode* y = x->right;
    x->right = y->left;

    if (y->left != t->NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == t->NIL)
        t->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotation(rbTree* t, treeNode* x) {
    treeNode* y = x->left;
    x->left = y->right;

    if (y->right != t->NIL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == t->NIL)
        t->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}

void insertionFixUp(rbTree* t, treeNode* z) {
    while (z->parent->color == 1)
    {
        if (z->parent == z->parent->parent->left)
        {
            treeNode* y = z->parent->parent->right;

            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotation(t, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                right_rotation(t, z->parent->parent);
            }
        }
        else
        {
            treeNode* y = z->parent->parent->left;

            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotation(t, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                left_rotation(t, z->parent->parent);
            }
        }
    }

    t->root->color = 0; // root to balck color
}

void insertion(rbTree* t, treeNode* z) {
    treeNode* y = t->NIL;
    treeNode* temp = t->root;

    while (temp != t->NIL)
    {
        y = temp;
        if (z->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    z->parent = y;

    if (y == t->NIL)
        t->root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    z->left = t->NIL;
    z->right = t->NIL;
    z->color = 1;

    insertion_fixup(t, z);
}

void inorder(rbTree* t, treeNode* n) {
    if (n != t->NIL)
    {
        inorder(t, n->left);
        printf("%d \n", n->data);
        inorder(t, n->right);
    }
}


