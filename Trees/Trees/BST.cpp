#include "BST.h"


bool checkSubTree(Node * node, int min, int max) {
	// check if node exists and within bounds: (min < data < max )
	if (node == nullptr) { return true; }
	if ((node->data) >= max){ return false; }
	if ((node->data) <= min){ return false; }

	// Check left and right nodes recursively
	if (!checkSubTree(node->left, min, node->data)) {return false;}
	if (!checkSubTree(node->right, node->data, max)) {return false;}

	return true;
}


bool isBST(Node * root){
	return checkSubTree(root, (MIN_VAL-1), (MAX_VAL+1) );
}