#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* mergeList(struct node* a, struct node* b);
void splitList(struct node* source, struct node** frontRef, struct node** backRef);
void printList(struct node *node)


struct node
{
	int data;
	struct node* next;
};

void merge(int * arr, int low, int high){
	int mid = (high+low)/2;
	int lowSize = mid - low + 1; 
	int highSize = high - mid;
	
	int lowHalf[lowSize]; 
	int highHalf[highSize]; 
	
	// Copy contents into temporary arrays
	 memcpy(lowHalf, arr+low, (lowSize) * sizeof(int));
	 memcpy(highHalf, arr+mid+1, (highSize) * sizeof(int));
	
	int i = 0;
	int j = 0;
	int k = low;
	
	
	
	// Compare and Sort here
	while(1){
		if(lowHalf[i] < highHalf[j]){
			arr[k] = lowHalf[i];
			i++;
			k++;
			if(i==lowSize) break;
		}else{
			arr[k] = highHalf[j];
			j++;
			k++;
			if(j==highSize) break;
		}
		
	}
	// Finish copying
	while(i<lowSize){
		arr[k] = lowHalf[i];
		i++;
		k++;
	}
	while(j<highSize){
		arr[k] = highHalf[j];
		j++;
		k++;
	}	

}

void msort(int * arr, int low, int high){
	int mid = (high+low)/2;
	
	if (high>low){
		msort(arr, low, mid);
		msort(arr, mid+1, high);
		merge(arr, low, high);
	}
}


void mergesort(int * arr, int len){
	msort(arr, 0, len-1);
} 



{



void printList(struct node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
int listLength(struct node * head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    // set front and back to head
    // Guaranteed length is 2+
    
    /* Debug
    printf("Original : "); 
    printList(source);
    */
    
    *frontRef = source; 
    struct node * ptr = source;
    int length = listLength(source);
    // move ptr to half way point
    for (int i = 0; i < length/2-1; i++){
        ptr = ptr->next;
    }
    // split the list
    *backRef = ptr->next;
    ptr->next = NULL;
    
    /* Debug
    printf("Front : "); 
    printList(*frontRef); 
    printf("Back : "); 
    printList(*backRef);
    */
    
}
// Returns 1 if a->data < b->data else 0
int compareNodes(struct node * a, struct node * b){
    if (a == NULL) return 0;
    if (b == NULL) return 1;
    return (a->data < b->data);    
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
    /* Debug
    printf("Merging\n");
    printf("A: ");printList(a);printf("B: ");printList(b);
    */
    // Initialize Head, a, b
    struct node * head = (compareNodes(a,b)) ? a : b;
    if (compareNodes(a,b)) {
        a = a->next;
    }else{
        b = b->next;
    }
    struct node * tail = head;
    // Compare and Merge
    while((a != NULL) || (b != NULL)){
        if (compareNodes(a,b)){
            tail->next = a;
            a = a->next;
        }else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    /* Debug
    printf("Head now: ");
    printList(head);
    */
    return head;
    
}

void mergeSortList(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;
    // Lenght < 2 is already sorted 
    if ((head == NULL) || (head->next == NULL)) return;
    splitList(head, &a, &b); 
    mergeSortList(&a);
    mergeSortList(&b);
    *headRef = mergeList(a, b);
}


int main(void){
	
	int x [] = {9,8,7,1,2,3,6,5,4};
	mergesort(x, 9);
	
	int i = 0;
	
	for (i = 0; i< 9; i++){
		printf("%d ", x[i]);
	}
	
	
	return 0;
}
