#include <iostream>
#include <stack>
# include <stdlib.h>
#include <queue>
#include <cmath>
using namespace std;

# define errorCode -5


struct binaryTreeNode
{
	int val;
	binaryTreeNode * left;
	binaryTreeNode * right;
	//int depth;
};

struct binaryTreeDepthNode
{
	int val;
	binaryTreeDepthNode * left;
	binaryTreeDepthNode * right;
	int depth;
};

struct linkedListNode{
	binaryTreeNode * btNode;
	linkedListNode * next;

};



void inOrderTraversal(binaryTreeNode * root){
	if(root == NULL){return;}

	inOrderTraversal(root->left);
	// VISIT NODE HERE
	inOrderTraversal(root->right);
}

void preOrderTraversal(binaryTreeNode * root){
	if (root == NULL) return;

	// VISIT NODE HERE
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(binaryTreeNode * root){
	if (root == NULL) return;
	
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	// VISIT NODE HERE
}

/* return vector of linked lists at each depth */
/* This is terribly done -> dont need to keep track of height of Node 
 * Just iterate through linked list of parent and add children to curr*/
/*
vector<linkedListNode *> depthLinkedLists(binaryTreeNode * root){
 	queue<binaryTreeNode *> btqueue;
 	vector<linkedListNode *> depthList;
 	linkedListNode * currTail = NULL;
 	int depth = -1;
 	if (root != NULL){
 		root->depth = 0;
 		btqueue.push(root);
 	}

 	while(!btqueue.empty()){

 		// dequeue it
 		binaryTreeNode * btNode = btqueue.front();
 		btqueue.pop();
 		// Enqueue children with updated heights (level order)
 		if(btNode->left != NULL){
 			btNode->left->depth = btNode->depth + 1;
 			btqueue.push(btNode->left);
 		}
 		if(btNode->right != NULL){
 			btNode->right->depth = btNode->depth + 1;
 			btqueue.push(btNode->right);
 		}

 		// creat new linked list Node
 		linkedListNode * newNode = new linkedListNode;
 		newNode->btNode = btNode;
 		newNode->next = NULL;
 		// Check if at new depth (need new linkedList)
 		if(btNode->depth != depth){
 			depthList.push_back(newNode);
 			currTail = newNode;
 			depth ++;
 		}
 		else{
 			currTail->next = newNode;
 		}

 	}

 	return depthList;
 }
*/
bool isBST(binaryTreeNode * root, int min, int max){
	// Assumes a NULL tree is valid
	if (root == NULL) return true;
	if ( (root->val < min  ) || (root->val >= max)) return false;

	return isBST(root->left, min , root->val) && 
		   isBST(root->right, root->val, max);
}


// Checks if binarySearchTree is valid (Assumes min max)
bool isBinarySearchTree(binaryTreeNode * root){
	int MIN = -1; int MAX = 0x0FFFFFF;
	return isBST(root, MIN, MAX);
}

/*
binaryTreeNode * findBSTSuccessor(binaryTreeNode * btNode){
	// if no right node, find parent
	if (btNode->right == NULL){
		int compVal = btNode->val;
		while(btNode->parent != NULL){
			btNode = btNode->parent;
			if (btNode->val >= compVal){
				return btNode;
			}
		}
		return NULL; // btNode was the max!
	 }

	 else{
	 	btNode = btNode->right;
	 	while(btNode->left != NULL){
	 		btNode = btNode->left;
	 	}

	 	return btNode;
	 }
}

*/
binaryTreeNode * findNode(binaryTreeNode * root, int key){
	if(root == NULL) return root;
	
	if (root->val == key) return root;
	binaryTreeNode * check = findNode(root->left, key);
	if(check != NULL) return check;
	check = findNode(root->right, key);
	if(check != NULL) return check;

	return NULL;
}

binaryTreeNode * lowestCommonAncestor(binaryTreeNode * root, int v1, int v2){
	if (root == NULL || root->val == v1 || root->val == v2) return root;
    bool onLeftOne = (findNode(root->left, v1) != NULL); 
	bool onLeftTwo = (findNode(root->left, v2) != NULL);
    if (onLeftOne == onLeftTwo) {
        if (onLeftOne) return lowestCommonAncestor(root->left, v1, v2);
        else return lowestCommonAncestor(root->right, v1, v2);
    }
    else return root;
}


binaryTreeNode * createBinaryTreeNode(int val, binaryTreeNode * left, binaryTreeNode * right){
	return new binaryTreeNode{val,left,right};
}


void inOrderPrint(binaryTreeNode * root){
	if(root == NULL){return;}

	inOrderPrint(root->left);
	cout << root->val << " ";
	inOrderPrint(root->right);
}

void addNodeBST(binaryTreeNode * root, binaryTreeNode * node){
	if (root == NULL || node == NULL){return;}

	if (node->val < root->val){
		if (root->left == NULL) root->left = node;
		else return addNodeBST(root->left, node);
	}
	else{
		if(root->right == NULL) root->right = node;
		else return addNodeBST(root->right, node);
	}
}


binaryTreeNode * minBSTHelper(binaryTreeNode * root, vector<int> sortedNums, int low, int high){

 	if (high < low) return root;
 	// Recursive case is to find midpoint
 	int mid = (low+high)/2;
 	binaryTreeNode *  newNode = createBinaryTreeNode(sortedNums[mid],NULL,NULL);
 	if (root == NULL) root = newNode;
 	else addNodeBST(root, newNode);

 		/* COULD JUST create a new tree everytime and say root->left = minBSTHelper(root, sortedNums, low, mid-1);
 		 * INSTEAD of using the addNodeBST method. This would save a lot of time! 
 		 */ 
 		minBSTHelper(root, sortedNums, low, mid-1);
 		minBSTHelper(root, sortedNums, mid+1, high);
 	return root;
}

binaryTreeNode * minBST(vector<int> sortedNums){
	return minBSTHelper(NULL, sortedNums, 0, sortedNums.size()-1);
}


void minBSTTest(){

	vector<int> testVector = {1,2,3,4,5,6,7,8,9,10};
	binaryTreeNode * bst = minBST(testVector);
	inOrderPrint(bst);
}
int max(int v1, int v2){
    if (v1 > v2) return v1;
    return v2;
}

int getHeightHelper(binaryTreeNode * root, int height){
    // don't care about NULL 
    if (root == NULL) return 0;
    // Compare to height of right and left
    int heightLeft = getHeight(root->left, height+1);
    int heightRight = getHeight(root->right, height+1);
    return max(height,max(heightLeft, heightRight));
}

int getHeight(binaryTreeNode * root){
	if (root == NULL) return -1;
	return getHeightHelper(root, 0);
}


int isBalancedHelper(binaryTreeNode * root){
	if (root == NULL) return -1;
	
	int leftHeight = isBalancedHelper(root->left);
	int rightHeight = isBalancedHelper(root->right);
	if ( leftHeight == errorCode) return errorCode;
	if ( right == errorCode) return errorCode;
	
	if(abs(rightHeight - leftHeight) > 1) return errorCode;

	return max(leftHeight, rightHeight) + 1;

}

bool isBalanced(binaryTreeDepthNode * root){
	return isBalancedHelper(root) != errorCode;
}


int main(void){
	//minBSTTest();


	return 0;
}