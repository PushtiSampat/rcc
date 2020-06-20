 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      5-reverse.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content: Write a program to reverse a given linked list 
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


/* gcc file-1.c file-2.c 
It will give error if any static func() exists

Static word is used to avoid conflict
By default, all functions are global. 
Reverse function may be used by any other program. 
By writing static, this function will work on this file only */


// Function for -> Reversing data 
static struct Node *reverse(struct Node *pHead)
{
    struct Node *temp; 
	struct Node *prev = NULL;
	struct Node *current = pHead; 

    while (current != NULL) { 

        temp = current -> next; 

        // Reverse current node's pointer 
        current -> next = prev; 
  
        // Move pointer one position ahead. 
        prev = current; 

        current = temp; 

    } 
    
    pHead = prev; 

    return pHead;
}

// Function for -> Displaying all elements of Linked List 
void display(struct Node *pHead)
{
	struct Node *rev = pHead;

	printf("\n ========== Result Starts ========== \n");

	while(rev != NULL) {
		printf("\n \t rev -> data: %d\n", rev -> data);
		rev = rev -> next;
	}

	printf("\n ========== Result Ends========== \n");
}


// Driver Code 
int main()
{
	struct Node *pHead = NULL;

	int num = getN();
	pHead = insertData(pHead, num);

	pHead = reverse(pHead);

	display(pHead);

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

	 ========== Result Starts ==========

	         rev -> data: 50

	         rev -> data: 40

	         rev -> data: 30

	         rev -> data: 20

	         rev -> data: 10

	 ========== Result Ends==========

 =================================================================*/