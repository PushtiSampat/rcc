 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      10-split.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a C program to split a given linked list into two.  
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

	printf(" Enter No. of nodes you want to enter: ");
	scanf("%d",&n);
	
	return n;
}


// Function for -> Getting data
int getData()
{
	int data;

	printf("\n Enter Data: ");
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



int countNodes(struct Node *p)
{
	int count = 0;
	
	while (p != NULL) {
		count ++;
		p = p -> next;		
	}

	return count;
}


void printStylish(int count)
{
	printf("\n ********");
	for (int i = 0; i < count; ++i) { 
		printf("************"); 
	}
	printf("\n");
}

// Function for -> Displaying all elements of Linked List 
void display(struct Node *pHead)
{
	int i = 0, count;
	struct Node *curr = pHead;

	count = countNodes(pHead);

	if(pHead == NULL) {
		printf(" ********* Empty List ********* \n");
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


int askSplitType()
{
	int splitType;
	
	printf(" How do you want to split \n\t 1. Using Index  \n\t 2. Using Value: \n \t ");
	scanf ("%d",&splitType);

	if(splitType == 1 || splitType == 2) { 
		return splitType;
	}
	else {
		printf(" *** Enter valid option *** \n");
		splitType = askSplitType();		
	}

}


int askIndex(int count)
{
	int n, index;

	printf("\n From which Index do you want to create a new List: ");
	scanf("%d",&index);

	if(index > 0 && index <= count) { 
		return index;
	}
	printf("Enter valid Index\n");
	n = askIndex(count);
	
}

struct Node *split(struct Node **pHead, int type)
{
	struct Node *curr = *pHead;
	struct Node *prev = *pHead;
	struct Node *newList;

	int i = 0, index, count, data, foundData;

	count = countNodes(*pHead);
	
	if(type == 1) {
		index = askIndex(count);
		while (curr != NULL) {
			if(++i == index){
				if(index == 1) {
					newList = *pHead;
					*pHead = NULL;
					return newList; 
				}
				newList = prev -> next;
				prev -> next = NULL;
				return newList; 
			}
			prev = curr;
			curr = curr -> next;		
		}
	} 

	else if(type == 2) {
		foundData = 0;
		data = getData();
		while (curr != NULL) {
			i++;
			if(data == curr -> data){
				foundData = 1;
				
				// Finding Duplicate Data
				curr = curr -> next;
				while (curr != NULL) {
					if(data == curr -> data) {
						printf(" ********* Duplicate record found. Enter Index no to split *********\n");
						newList = split(&(*pHead), 1);						
						return newList;
					}
					curr = curr -> next;
				}

				if(i == 1) {
					newList = *pHead;
					*pHead = NULL;
					return newList; 
				}
				newList = prev -> next;
				prev -> next = NULL;
				return newList; 
			}
			prev = curr;
			curr = curr -> next;		
		}
		if(!foundData) {
			printf(" \n ********* Data not found ********* \n");
		}
		
	}
}


int main()
{
	struct Node *pHead = NULL;
	struct Node *newList;
	
	int type;
	int num = getN();

	pHead = insertData(pHead, num);

	display(pHead);

	type = askSplitType();

	newList = split(&pHead, type);

	printf(" \n ========== List 1 ==========\n");
	display(pHead);

	printf(" \n ========== List 2 ==========\n");
	display(newList);

	return 0;
}


/* =================================================================
* Output :

	 Enter No. of nodes you want to enter: 5

	 Enter Data: 10

	 Enter Data: 20

	 Enter Data: 30

	 Enter Data: 20

	 Enter Data: 50

	 ********************************************************************
	 * Index *        1 *         2 *         3 *         4 *         5 *
	 ********************************************************************
	 * Data  *       10 *        20 *        30 *        20 *        50 *
	 ********************************************************************
	 * Next  * 12785096 *  12788400 *  12788416 *  12788432 *         0 *
	 ********************************************************************
	 How do you want to split
	         1. Using Index
	         2. Using Value:
	         2

	 Enter Data: 20
	 ********* Duplicate record found. Enter Index no to split *********

	 From which Index do you want to create a new List: 3

	 ========== List 1 ==========

	 ********************************
	 * Index *        1 *         2 *
	 ********************************
	 * Data  *       10 *        20 *
	 ********************************
	 * Next  * 12785096 *         0 *
	 ********************************

	 ========== List 2 ==========

	 ********************************************
	 * Index *        1 *         2 *         3 *
	 ********************************************
	 * Data  *       30 *        20 *        50 *
	 ********************************************
	 * Next  * 12788416 *  12788432 *         0 *
	 ********************************************

==================================================================== */