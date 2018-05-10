#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Node{
	int data;
	Node * next;
};

/* return kth to last element of linked list*/
Node * fromLast(Node * head, int k){
	Node * tail = head;
	for (int i = 0; i < k; i++){
		tail = tail->next;
	}

	while(tail != NULL){
		head = head->next;
		tail = tail->next;
	}

	return head;
}


void deleteList(Node * head){
	Node * ptr = head; 
	while(ptr != NULL){
		head = ptr->next;
		delete ptr;
		ptr = head;
	}
}


void fromLastTest(){
	Node * head = new Node;
	Node * ptr = head;
	head->data = 0;

	for (int i = 1; i < 10; i++){
		Node * x = new Node;
		x->data = i;
		x->next = NULL;
		ptr->next = x;
		ptr = ptr->next;
	}

	int k = 4;
	Node * kth = fromLast(head, k);
	printf("%d is %dth from last", kth->data, k);

	/* delete the linked list */

	deleteList(head);	
}

/* Each node contains a digit --> reverse means 1's digit is head */
int addLinkedLists(Node * headA, Node * headB, bool reverse){
	int sum = 0;
	int multiplier = 1;
	if (reverse){

		while(headA != NULL || headB != NULL){
			int a = 0 , b = 0;
			if (headA != NULL){
				a = headA->data;
				headA = headA->next; 
			}
			if (headB != NULL){
				b = headB->data;
				headB = headB->next; 
			}
			sum += (a + b) * multiplier;
			multiplier *= 10;
			
		}
	}
	return sum;

}

void addLinkedListsTest(){

	Node * headA = new Node;
	Node * headB = new Node;
	headA->data = 1;
	headB->data = 2;

	// int 3211
	Node * ptr = headA;
	for (int i = 1; i < 4; i++){
		Node * x = new Node;
		x->data = i;
		x->next = NULL;
		ptr->next = x;
		ptr = ptr->next;
	}

	// int 212
	ptr = headB;
	for (int i = 1; i < 3; i++){
		Node * x = new Node;
		x->data = i;
		x->next = NULL;
		ptr->next = x;
		ptr = ptr->next;
	}

	printf("Sum is %d", addLinkedLists(headA, headB, true));

	deleteList(headA);
	deleteList(headB);


}

int main(void){

	//fromLastTest();
	addLinkedListsTest();

	return 0;
}