
 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      4-ordered.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to create an ordered linked list 
 * 
 * ========================================================== */


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Structure created
struct Node
{
	int data;
	struct Node *next;
};

// Function for -> Getting Number of elements user wants to enter
int getN()
{
	int n;

	printf("Enter No. of nodes you want to enter: ");
	scanf("%d",&n);

	if(n < 1) { 
		printf("Enter positive natural number\n");
		n = getN();
	}
	
	return n;
}


// Function for -> Getting element
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


// Function for inserting data order wise
struct Node *insert(struct Node *pHead, int n)
{
	int i, data;

	struct Node *new_node;
	struct Node *curr;
	struct Node *prev = NULL;

	if(pHead == NULL) {
		pHead = createNode();

		pHead -> data = getData();
		pHead -> next = NULL;

		if(n == 1) { return pHead; }
	}

	for(i = 1; i < n; i++) {

		curr = pHead;

		data = getData();
		new_node = createNode();
		
		while(curr != NULL) {

			if(curr -> data >= data) {
				new_node -> data = data;
				new_node -> next = curr;
				
				if(curr == pHead) {
					pHead = new_node;
				}

				else {
					prev -> next = new_node;
				}

				break;
			} 

			prev = curr;
			curr = curr ->next;

		}

		if(curr == NULL) {
			prev -> next = new_node;
			new_node -> data = data;
			new_node -> next = NULL;
		}

	}

	return pHead;
}

// Function for -> Displaying all elements of Linked List
void display(struct Node *pHead)
{
	struct Node *curr = pHead;

	printf("\n ========== Result Starts ========== \n");

	while(curr != NULL) {
		printf("\n \t         curr: %10d\n", curr);
		printf(" \t curr -> data: %10d\n", curr -> data);
		printf(" \t curr -> next: %10d\n", curr -> next);
		curr = curr -> next;
	}

	printf("\n ========== Result Ends========== \n");
}

// Driver Function
int main()
{
	struct Node *pHead = NULL;

	pHead = insert(pHead, getN());

	display(pHead);

	return 0;
}

/* =================================================================
 * Output :
	 Enter No. of nodes you want to enter: 7

	Enter Data: 30

	Enter Data: 40

	Enter Data: 20

	Enter Data: 10

	Enter Data: 60

	Enter Data: 50

	Enter Data: 70

	 ========== Result Starts ==========

	                 curr:   10363584
	         curr -> data:         10
	         curr -> next:   10363568

	                 curr:   10363568
	         curr -> data:         20
	         curr -> next:   10360216

	                 curr:   10360216
	         curr -> data:         30
	         curr -> next:   10360264

	                 curr:   10360264
	         curr -> data:         40
	         curr -> next:   10363616

	                 curr:   10363616
	         curr -> data:         50
	         curr -> next:   10363600

	                 curr:   10363600
	         curr -> data:         60
	         curr -> next:   10363632

	                 curr:   10363632
	         curr -> data:         70
	         curr -> next:          0

	 ========== Result Ends==========

 ================================================================= */

