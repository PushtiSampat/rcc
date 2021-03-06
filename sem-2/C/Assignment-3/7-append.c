

 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      7-append.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to create two linked list and 
 * 			 append the second list after the first
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
		if((pHead = (struct Node *) malloc(sizeof(struct Node))) == NULL) {
			perror("\n Error");
			exit(1);
		}

		pHead -> data = getData();
		pHead -> next = NULL;
		
		if (n == 1) { return pHead; }
	}

	for(i = 1; i < n; i++) {

		temp = pHead;
		
		if((new_node = (struct Node *) malloc(sizeof(struct Node))) == NULL) {
			perror("\n ** Sufficient Memory Not Available ** \n");
			exit(1);
		}

		new_node -> data = getData();
		new_node -> next = NULL;

		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new_node;

	}

	return pHead;
}


// Function for -> Appending List2 with List1 
void appendList(struct Node *L1, struct Node *L2)
{
	struct Node *temp = L1;
	while(temp != NULL) {
			
		if(temp -> next == NULL) {
			temp -> next = L2;
			break;
		}

		temp = temp -> next;
	}
}

// Function for -> Displaying all elements of Linked List 1
void display(struct Node *pHead)
{
	struct Node *append = pHead;

	printf("\n ========== Result Starts ========== \n");

	while(append != NULL) {
		printf("\nappend -> data: %d\n", append -> data);
		append = append -> next;
	}

	printf("\n ========== Result Ends========== \n");
}

int main()
{
	struct Node *list1 = NULL;
	struct Node *list2 = NULL;

	printf("\n ========== Linked List 1 ==========\n");
	int num = getN();
	list1 = insertData(list1, num);

	printf("\n ========== Linked List 2 ==========\n");
	
	num = getN();
	list2 = insertData(list2, num);

	appendList(list1, list2);

	display(list1);

	return 0;
}

/* =================================================================

Output :

	 ========== Linked List 1 ==========
	Enter No. of nodes you want to enter: 4

	Enter Data: 50

	Enter Data: 20

	Enter Data: 10

	Enter Data: 60

	 ========== Linked List 2 ==========
	Enter No. of nodes you want to enter: 3

	Enter Data: 30

	Enter Data: 40

	Enter Data: 70

	 ========== Result Starts ==========

	append -> data: 50

	append -> data: 20

	append -> data: 10

	append -> data: 60

	append -> data: 30

	append -> data: 40

	append -> data: 70

	 ========== Result Ends==========

 ================================================================= */


