#pragma once

typedef struct treeNode {
	struct treeNode* parent;
	struct treeNode* left;
	struct treeNode* right;
	int data; // in reservation system, data of rbtree is 
	int color;
} treeNode;

typedef struct RbTree {
	treeNode* root;
	treeNode* NIL;

} RbTree;

treeNode* newNode(int data);
RbTree* newRbTree();
void left_rotation(RbTree* t, treeNode* x);
void right_rotation(RbTree* t, treeNode* x);
void insertion_fixup(RbTree* t, treeNode* z);
void insertion(RbTree* t, treeNode* z);
void inorder(RbTree* t, treeNode* n);