 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      9-swap-consecutive-using-addr.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to swap two consecutive elements 
 * 			 ( Swap only address )
 * 
 * ========================================================== */


#include <stdio.h>
// #include <conio.h>
#include <stdlib.h> 


// Structure -> Node
struct Node
{
	int data;
	struct Node *next;
};


// Function for -> Getting N
int getN()
{
	int n;

	printf("Enter No. of nodes you want to enter: ");
	scanf("%d",&n);
	
	return n;
}


// Function for -> Getting data
int getData()
{
	int data;

	printf("\nEnter Data: ");
	scanf("%d",&data);
	
	return data;
}


// Function for -> Creating Node 
struct Node *createNode()
{
	struct  Node *new_node;

	if((new_node = (struct Node *) malloc(sizeof(struct Node))) == NULL) {
		perror ("Error");
		exit(1);
	}

	return new_node;
}


// Function For -> Inserting Data
struct Node *insertData(struct Node *pHead, int n)
{
	int i, data;
	struct Node *new_node;
	struct Node *temp;

	if(pHead == NULL) {

		pHead = createNode();

		pHead -> data = getData();
		pHead -> next = NULL;

		if (n == 1) { return pHead; }
	}

	for(i = 1; i < n; i++) {

		temp = pHead;
		
		new_node = createNode();

		new_node -> data = getData();
		new_node -> next = NULL;


		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new_node;
	}

	return pHead;
}


// Function for -> Displaying all elements of Linked List 
void display(struct Node *pHead)
{
	struct Node *iterate = pHead;

	while(iterate != NULL) {
		printf("\niterate -> data: %d\n", iterate -> data);
		printf("iterate -> next: %d\n", iterate -> next);
		iterate = iterate -> next;
	}

}


// Function for -> Swapping consecutive elements 
void swap(struct Node **pHead)
{
	struct Node *curr;
	struct Node *temp;
	struct Node *prev = *pHead;

	if((*pHead) -> next == NULL) {
		printf("Swap not possible in 1 element \n");
		exit(0);
	}

	curr = (*pHead) -> next;
	
	*pHead = curr;

	while(curr != NULL) {

		if(curr -> next == NULL) {
			curr -> next = prev;
			prev -> next = NULL;
			return;
		}	

		else {
			
			if(curr -> next -> next ==  NULL) {
				prev -> next = curr ->next;
				curr -> next = prev;
				return;
			} 

			else {
				temp = curr -> next;
				prev -> next = curr -> next -> next;
				curr -> next = prev;
				
				if(prev -> next -> next == NULL) {
					prev -> next -> next = temp;
					temp -> next = NULL;
					return;
				}

			}

		}	
		
		prev = temp;
		curr = curr -> next -> next;

	}
	
}


// Driver Code
int main()
{
	struct Node *pHead = NULL;
	int num = getN();

	pHead = insertData(pHead, num);

	printf("\n ========== Before Swap ========== \n");
	display(pHead); //Display all Nodes before swap

	swap(&pHead);

	printf("\n ========== After Swap ========== \n");
	display(pHead); //Display all Nodes after swap

	return 0;
}

/* =================================================================

Output :

	Enter No. of nodes you want to enter: 7

	Enter Data: 10

	Enter Data: 20

	Enter Data: 30

	Enter Data: 40

	Enter Data: 50

	Enter Data: 60

	Enter Data: 70

	 ========== Before Swap ========== 

	iterate -> data: 10
	iterate -> next: 29098032

	iterate -> data: 20
	iterate -> next: 29098064

	iterate -> data: 30
	iterate -> next: 29098096

	iterate -> data: 40
	iterate -> next: 29098128

	iterate -> data: 50
	iterate -> next: 29098160

	iterate -> data: 60
	iterate -> next: 29098192

	iterate -> data: 70
	iterate -> next: 0

	 ========== After Swap ========== 

	iterate -> data: 20
	iterate -> next: 29098000

	iterate -> data: 10
	iterate -> next: 29098096

	iterate -> data: 40
	iterate -> next: 29098064

	iterate -> data: 30
	iterate -> next: 29098160

	iterate -> data: 60
	iterate -> next: 29098128

	iterate -> data: 50
	iterate -> next: 29098192

	iterate -> data: 70
	iterate -> next: 0	

 ================================================================= */