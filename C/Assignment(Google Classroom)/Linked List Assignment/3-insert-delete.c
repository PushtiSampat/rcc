

 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      3-insert-delete.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a menu driven program to create a singly linked list 
 *			 and perform following operations on it:
 *       
 *   		 a. Insert an element 
 * 			 b. Delete an element
 * 			 c. Display the list
 * 
 * ========================================================== */


#include<stdio.h>
#include<stdlib.h>

// Structure
struct Node
{
	int data;
	struct Node *next;
};


// Function for -> asking choice
int askChoice()
{
	int choice;
	
	// printf("\n =============== Asking Choice ===============\n");
	printf("\n Enter your Choice\n\n\t 0. Exit\n\t 1. Insert\n\t 2. Display\n\t 3. Delete\n");
	
	printf("\n\t My choice is: ");
	scanf("%d",&choice);
	
	return choice;
}


// Function for -> Style
void printStylish(int count)
{
	printf("\n ********");
	for (int i = 0; i < count; ++i) { 
		printf("************"); 
	}
	printf("\n");
}


// Function for -> Couting Nodes
int countNodes(struct Node *p)
{
	int count = 0;
	
	while (p != NULL) {
		count ++;
		p = p -> next;		
	}
	return count;
}


// Function for -> Displaying all elements of Linked List 
void display(struct Node *pHead)
{
	int i = 0, count;
	struct Node *curr = pHead;

	count = countNodes(pHead);

	if(pHead == NULL) {
		printf("\n ********* Empty List ********* \n");
		return;
	}

	printStylish(count);
	
	printf(" * Index *");
	while(curr != NULL) {
		printf(" %8d * ", ++i);
		curr = curr -> next;
	}

	printStylish(count);
	curr = pHead;

	printf(" * Data  *");
	while(curr != NULL) {
		printf(" %8d * ", curr -> data);
		curr = curr -> next;
	}

	printStylish(count);
	curr = pHead;

	printf(" * Next  *");
	while(curr != NULL) {
		printf(" %8d * ", curr -> next);
		curr = curr -> next;
	}

	printStylish(count);
	
}

// Function for -> asking any element to Insert 
int askElement ()
{
	int element;

	printf("Enter data: ");
	scanf("%d",&element);
	
	return element;	
}

void insertAtLast(struct Node **pHead, int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *pHead;

	new_node->data = data;
	new_node->next = NULL;

	while(last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;
	
	return;
}


void insertAtStart(struct Node **pHead, int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = data;
	new_node->next = *pHead;
	*pHead = new_node;
	
	return;
}


int askIndex(int count)
{
	int n, index;

	printf("\n After which Index do you want to create a new Node: ");
	scanf("%d",&index);

	if(index > 0 && index <= count) { 
		return index;
	}
	printf("\n Enter valid Index");
	n = askIndex(count);	
}


int askIndexToDel(int count)
{
	int n, index;

	printf("\n Which Index do you want to delete: ");
	scanf("%d",&index);

	if(index > 0 && index <= count) { 
		return index;
	}
	printf("Enter valid Index\n");
	n = askIndex(count);	
}


void insertAtSpecific(struct Node **pHead, int data)
{
	int position, index, i = 0;
	struct Node *curr = *pHead;
	struct Node *temp;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	display(*pHead);
	index = askIndex(countNodes(*pHead));


	while (curr != NULL) {

		if(++i == index) {

			new_node -> data = data;
			
			if(curr -> next == NULL) {
				curr -> next = new_node;
				new_node -> next = NULL;
			} 

			else {
				temp = curr -> next;
				curr -> next = new_node;
				new_node -> next = temp;
			}

		}	

		curr = curr -> next	;

	}

}


static void delete(struct Node **pHead)
{
	int position, index, i = 0, count;
	struct Node *curr = *pHead;
	struct Node *prev = NULL;
	if(*pHead == NULL) {
		return;
	}
	display(*pHead);

	count = countNodes(*pHead);
	index = askIndexToDel(count);

	while (curr != NULL) {

		if(++i == index) {

			if(i == 1) {

				if(count == 0) {
					free(*pHead);
					*pHead = NULL;
					printf("\n\t *** Index Deleted *** \n");
					return;
				}

				else {
					*pHead = curr -> next;
					free(curr);
					printf("\n\t *** Index Deleted *** \n");
					return;
				}

			}

			else {

				if(curr -> next == NULL) {
					free(curr);
					prev -> next = NULL;					
					printf("\n\t *** Index Deleted *** \n");
					return;
				}

				else {
					prev -> next = curr -> next;
					free(curr);
					printf("\n\t *** Index Deleted *** \n");
					return;
				}

			}

		}	

		prev = curr;
		curr = curr -> next	;

	}

}


void insert(struct Node **pHead, int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	int insertChoice;

	// If linked List is empty 
	if(*pHead == NULL) {
		*pHead = new_node;
		new_node->data = data;
		new_node->next = NULL;
		display(*pHead);
		return;
	}

	printf("\nWhere do you want to insert \n\t 1. Enter at Beginning \n\t 2. Enter at desired location \n"
		" \t 3. Enter at  end \n\n\t Enter Option: ");
	scanf("%d",&insertChoice);

	if(insertChoice == 1) {
		insertAtStart(pHead, data);
	}

	else if (insertChoice == 2) {
		insertAtSpecific(pHead, data);
	} 

	else if (insertChoice == 3) {
		insertAtLast(pHead, data);
	}

	display(*pHead);
}



// Function for -> performing tasks as per choice
void doTask(struct Node **pHead, int choice)
{
	if(choice == 1) {
		printf("\n ========== Enter data you want to insert ==========\n");
		insert(pHead, askElement());
	} 

	else if(choice == 2) {
		display(*pHead);
	} 

	else if(choice == 3) {
		delete(&(*pHead));
		display(*pHead);
	}

	else {
		printf("\n * * * Invalid Choice * * * \n"); 
	}
}

// Driver Function
int main()
{
	struct Node *pHead = NULL;
	int choice = 1;
	
	while(choice = askChoice()) {
		doTask(&pHead, choice);
	}
	
	return 0;
}






/* =================================================================

Output :

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 20

	 ********************
	 * Index *        1 *
	 ********************
	 * Data  *       20 *
	 ********************
	 * Next  *        0 *
	 ********************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 10

	Where do you want to insert
	         1. Enter at Beginning
	         2. Enter at desired location
	         3. Enter at  end

	         Enter Option: 1

	 ********************************
	 * Index *        1 *         2 *
	 ********************************
	 * Data  *       10 *        20 *
	 ********************************
	 * Next  *  7607704 *         0 *
	 ********************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 40

	Where do you want to insert
	         1. Enter at Beginning
	         2. Enter at desired location
	         3. Enter at  end

	         Enter Option: 3

	 ********************************************
	 * Index *        1 *         2 *         3 *
	 ********************************************
	 * Data  *       10 *        20 *        40 *
	 ********************************************
	 * Next  *  7607704 *   7611088 *         0 *
	 ********************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 30

	Where do you want to insert
	         1. Enter at Beginning
	         2. Enter at desired location
	         3. Enter at  end

	         Enter Option: 2

	 ********************************************
	 * Index *        1 *         2 *         3 *
	 ********************************************
	 * Data  *       10 *        20 *        40 *
	 ********************************************
	 * Next  *  7607704 *   7611088 *         0 *
	 ********************************************

	 After which Index do you want to create a new Node: 3

	 ********************************************************
	 * Index *        1 *         2 *         3 *         4 *
	 ********************************************************
	 * Data  *       10 *        20 *        40 *        30 *
	 ********************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *         0 *
	 ********************************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 50

	Where do you want to insert
	         1. Enter at Beginning
	         2. Enter at desired location
	         3. Enter at  end

	         Enter Option: 2

	 ********************************************************
	 * Index *        1 *         2 *         3 *         4 *
	 ********************************************************
	 * Data  *       10 *        20 *        40 *        30 *
	 ********************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *         0 *
	 ********************************************************

	 After which Index do you want to create a new Node: 4

	 ********************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *
	 ********************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *
	 ********************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 1

	 ========== Enter data you want to insert ==========
	Enter data: 60

	Where do you want to insert
	         1. Enter at Beginning
	         2. Enter at desired location
	         3. Enter at  end

	         Enter Option: 2

	 ********************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *
	 ********************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *
	 ********************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************************

	 After which Index do you want to create a new Node: 6
	 
	 Enter valid Index
	 After which Index do you want to create a new Node: 0
	 
	 Enter valid Index
	 After which Index do you want to create a new Node: 5

	 ********************************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *         6 *
	 ********************************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *        60 *
	 ********************************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *   7611184 *         0 *
	 ********************************************************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *         6 *
	 ********************************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *        60 *
	 ********************************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *   7611184 *         0 *
	 ********************************************************************************

	 Which Index do you want to delete: 6

	         *** Index Deleted ***

	 ********************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *
	 ********************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *
	 ********************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *
	 ********************************************************************
	 * Data  *       10 *        20 *        40 *        30 *        50 *
	 ********************************************************************
	 * Next  *  7607704 *   7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************************

	 Which Index do you want to delete: 1

	         *** Index Deleted ***

	 ********************************************************
	 * Index *        1 *         2 *         3 *         4 *
	 ********************************************************
	 * Data  *       20 *        40 *        30 *        50 *
	 ********************************************************
	 * Next  *  7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************************************************
	 * Index *        1 *         2 *         3 *         4 *
	 ********************************************************
	 * Data  *       20 *        40 *        30 *        50 *
	 ********************************************************
	 * Next  *  7611088 *   7611120 *   7611152 *         0 *
	 ********************************************************

	 Which Index do you want to delete: 3

	         *** Index Deleted ***

	 ********************************************
	 * Index *        1 *         2 *         3 *
	 ********************************************
	 * Data  *       20 *        40 *        50 *
	 ********************************************
	 * Next  *  7611088 *   7611152 *         0 *
	 ********************************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************************************
	 * Index *        1 *         2 *         3 *
	 ********************************************
	 * Data  *       20 *        40 *        50 *
	 ********************************************
	 * Next  *  7611088 *   7611152 *         0 *
	 ********************************************

	 Which Index do you want to delete: 3

	         *** Index Deleted ***

	 ********************************
	 * Index *        1 *         2 *
	 ********************************
	 * Data  *       20 *        40 *
	 ********************************
	 * Next  *  7611088 *         0 *
	 ********************************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************************
	 * Index *        1 *         2 *
	 ********************************
	 * Data  *       20 *        40 *
	 ********************************
	 * Next  *  7611088 *         0 *
	 ********************************

	 Which Index do you want to delete: 2

	         *** Index Deleted ***

	 ********************
	 * Index *        1 *
	 ********************
	 * Data  *       20 *
	 ********************
	 * Next  *        0 *
	 ********************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 2

	 ********************
	 * Index *        1 *
	 ********************
	 * Data  *       20 *
	 ********************
	 * Next  *        0 *
	 ********************

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********************
	 * Index *        1 *
	 ********************
	 * Data  *       20 *
	 ********************
	 * Next  *        0 *
	 ********************

	 Which Index do you want to delete: 1

	         *** Index Deleted ***

	 ********* Empty List *********

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 3

	 ********* Empty List *********

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 4

	 * * * Invalid Choice * * *

	 Enter your Choice

	         0. Exit
	         1. Insert
	         2. Display
	         3. Delete

	         My choice is: 0

 ================================================================= */

