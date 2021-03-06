
 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      1-fifo.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to create a singly linked list 
 * 			and display its elements in FIFO pattern.
 * 			Also display the number of elements in the list  
 * 
 * ========================================================== */


#include <stdio.h>
#include <conio.h>
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
		
		if (n == 1) { return pHead; } // only 1 element
	}

	for(i = 1; i < n; i++) {

		temp = pHead;
		
		// Creating new node
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
	struct Node *curr = pHead;

	printf("\n ========== Result Starts ========== \n");

	while(curr != NULL) {
		printf("\ncurr -> data: %d\n", curr -> data);
		printf("curr -> next: %d\n", curr -> next);
		curr = curr -> next;
	}

	printf("\n ========== Result Ends========== \n");
}


// Function for -> Counting nodes
int countNodes(struct Node *p)
{
	int count = 0;
	
	while (p != NULL) {
		count ++;
		p = p -> next;		
	}

	return count;
}


// Driver Code
int main()
{
	struct Node *pHead = NULL;
	int num = getN();

	pHead = insertData(pHead, num);

	display(pHead); //Display all Nodes

	printf("\nThere are %d elements in the list\n", countNodes(pHead));

	return 0;
}

/* =================================================================
 * Output :

	Enter No. of nodes you want to enter: 6

	Enter Data: 10

	Enter Data: 50

	Enter Data: 20

	Enter Data: 30

	Enter Data: 40

	Enter Data: 90

	 ========== Result Starts ==========

	curr -> data: 10
	curr -> next: 8197576

	curr -> data: 50
	curr -> next: 8200880

	curr -> data: 20
	curr -> next: 8200896

	curr -> data: 30
	curr -> next: 8200912

	curr -> data: 40
	curr -> next: 8200928

	curr -> data: 90
	curr -> next: 0
	
	 ========== Result Ends==========

	There are 6 elements in the list

 ================================================================= */

