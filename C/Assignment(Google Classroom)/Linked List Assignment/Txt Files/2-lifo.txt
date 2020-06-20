 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      2-lifo.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to create a singly linked list 
 * 			and display its elements in LIFO pattern.
 * 			Also display the number of elements in the list  
 * 
 * ========================================================== */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

// Function for -> Asking number of Elements
int num()
{
	int n;

	printf("How much elements you wanna enter: ");
	scanf("%d",&n);

	return n;
}

// Function for -> Getting Data from user
int getElement()
{
	int data;

	printf("Enter Data: ");
	printf("     ^^^^^\n");

	scanf("%d",&data);

	return data;
}

// Function for -> Creating new node
struct Node *createNode()
{
	struct  Node *new_node;

	// Sufficient memory not available
	if((new_node = (struct Node *) malloc(sizeof(struct Node))) == NULL ) {
		perror ("Error");
		exit(1);
	}

	return new_node;
}



void printStylish(struct Node *new_node)
{
	int j, k;
	
	for(j = 17; j < 24; j++) {
	
		for (k = 0; k < j; k++) {
			printf(" ");
		}

		for (k = 0; k < j - 17; k++) {
			printf("     ");
		}

		printf("*****\n");
	
	}

	printf("                                                            \\/\\/\\/\\/\\/ \n");
	printf("**********************************************************************\n");
	printf("** new_node: %8d || ", new_node);
	printf(" data    : %8d || ", new_node->data);
	printf(" next    : %8d ** ", new_node->next);
	printf("\n**********************************************************************\n");
}


// Function for -> Inserting Data
struct Node *insert(struct Node *pHead, int n)
{
	int i, j, k, data;
	struct  Node *new_node; 
	struct Node *temp;

	new_node = createNode();

	printf("\n                 ********\n");
	printf("                 * NULL *\n");
	printf("                 ********\n");

	if(pHead == NULL) {

		pHead = new_node;

		new_node -> data = getElement();
		new_node -> next = NULL;

		if(n == 1) { return pHead; }
		printStylish(new_node);
	
	}

	for (i = 1; i < n; ++i) {
		
		temp = new_node;	

		new_node = createNode();
		new_node -> data = getElement();
		new_node -> next = temp;
		
		printStylish(new_node);

	}

	return new_node;
}


// Function for -> Displaying Nodes
void display(struct Node *first)
{
	struct Node *disp = first;

	printf("\n========== Result ==========\n");
	
	while(disp != NULL) {

		printf("\ndisp: %d\n", disp);
		printf("disp -> data: %d\n", disp -> data);
		printf("disp -> next: %d\n", disp -> next);
		
		disp = disp -> next;
	}

	printf("\ndisp: %d\n", disp);
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
	struct Node *first;

	first = insert(pHead, num());

	display(first);

	printf("\nThere are %d elements in the list\n", countNodes(first));

	
	return 0;
}

/* =================================================================
 * Output :

	 How much elements you wanna enter: 5

	                 ********
	                 * NULL *
	                 ********
	Enter Data:      ^^^^^
	20
	                 *****
	                       *****
	                             *****
	                                   *****
	                                         *****
	                                               *****
	                                                     *****
	                                                            \/\/\/\/\/
	**********************************************************************
	** new_node:  7083416 ||  data    :       20 ||  next    :        0 **
	**********************************************************************
	Enter Data:      ^^^^^
	10
	                 *****
	                       *****
	                             *****
	                                   *****
	                                         *****
	                                               *****
	                                                     *****
	                                                            \/\/\/\/\/
	**********************************************************************
	** new_node:  7083464 ||  data    :       10 ||  next    :  7083416 **
	**********************************************************************
	Enter Data:      ^^^^^
	30
	                 *****
	                       *****
	                             *****
	                                   *****
	                                         *****
	                                               *****
	                                                     *****
	                                                            \/\/\/\/\/
	**********************************************************************
	** new_node:  7086768 ||  data    :       30 ||  next    :  7083464 **
	**********************************************************************
	Enter Data:      ^^^^^

	40
	                 *****
	                       *****
	                             *****
	                                   *****
	                                         *****
	                                               *****
	                                                     *****
	                                                            \/\/\/\/\/
	**********************************************************************
	** new_node:  7086784 ||  data    :       40 ||  next    :  7086768 **
	**********************************************************************
	Enter Data:      ^^^^^
	50
	                 *****
	                       *****
	                             *****
	                                   *****
	                                         *****
	                                               *****
	                                                     *****
	                                                            \/\/\/\/\/
	**********************************************************************
	** new_node:  7086800 ||  data    :       50 ||  next    :  7086784 **
	**********************************************************************

	========== Result ==========

	disp: 7086800
	disp -> data: 50
	disp -> next: 7086784

	disp: 7086784
	disp -> data: 40
	disp -> next: 7086768

	disp: 7086768
	disp -> data: 30
	disp -> next: 7083464

	disp: 7083464
	disp -> data: 10
	disp -> next: 7083416

	disp: 7083416
	disp -> data: 20
	disp -> next: 0

	disp: 0

	There are 5 elements in the list

 ================================================================= */