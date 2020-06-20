 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      8-swap-consecutive-using-values.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to swap two consecutive elements 
 * 			 ( Swap only values )
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
		printf("iterate -> data: %d\n", iterate -> next);
		iterate = iterate -> next;
	}

}


// Function for -> Swapping consecutive elements 
void swap(struct Node *pHead)
{
	struct Node *curr;
	struct Node *prev = pHead;

	int swap;

	if(pHead -> next == NULL) {
		printf("Swap not possible in 1 element \n");
		exit(0);
	}

	curr = pHead -> next;

	while(curr != NULL) {

		swap = prev -> data;
		prev -> data = curr -> data;
		curr -> data = swap;

		if(curr -> next == NULL || curr -> next -> next == NULL) {
			return;
		}

		prev = curr -> next;
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

	swap(pHead);

	printf("\n ========== After Swap ========== \n");
	display(pHead); //Display all Nodes after swap

	return 0;
}

/* =================================================================

Output :

	Enter No. of nodes you want to enter: 5

	Enter Data: 10

	Enter Data: 20

	Enter Data: 30

	Enter Data: 40

	Enter Data: 50

	 ========== Before Swap ==========

	iterate -> data: 10
	iterate -> data: 7083464

	iterate -> data: 20
	iterate -> data: 7086768

	iterate -> data: 30
	iterate -> data: 7086784

	iterate -> data: 40
	iterate -> data: 7086800

	iterate -> data: 50
	iterate -> data: 0

	 ========== After Swap ==========

	iterate -> data: 20
	iterate -> data: 7083464

	iterate -> data: 10
	iterate -> data: 7086768

	iterate -> data: 40
	iterate -> data: 7086784

	iterate -> data: 30
	iterate -> data: 7086800

	iterate -> data: 50
	iterate -> data: 0

 ================================================================= */