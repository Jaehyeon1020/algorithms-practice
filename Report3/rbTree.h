#pragma once

typedef struct treeNode {
	struct treeNode* parent;
	struct treeNode* left;
	struct treeNode* right;
	int data; // in reservation system, data of rbtree is 
	int color;
} treeNode;

typedef struct rbTree {
	treeNode* root;
	treeNode* NIL;

} rbTree;

treeNode* newNode(int data);
rbTree* newRbTree();
void leftRotation(rbTree* t, treeNode* x);
void rightRotation(rbTree* t, treeNode* x);
void insertionFixUp(rbTree* t, treeNode* z);
void insertion(rbTree* t, treeNode* z);
void inorder(rbTree* t, treeNode* n);