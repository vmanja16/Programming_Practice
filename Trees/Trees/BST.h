#pragma once

#define MAX_VAL 0
#define MIN_VAL 1000

struct Node {
	int data;
	Node * left;
	Node * right;
};

/* Helper function used to recursively verify subtree
 * follows min/max BST rules
*/
bool checkSubTree(Node * node, int min, int max);

/* This function analyzes a tree and determines if it is a valid BST following the rules:

 * The  value of every node in a node's left subtree is less than the data value of that node.
 * The  value of every node in a node's right subtree is greater than the data value of that node.
*/
bool isBST(Node * root);