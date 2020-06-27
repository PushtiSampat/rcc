


 /* ===========================================================
 
 * Roll No: 30
 * 
 * File:      6-sum.c
 * Copyright: 29-Apr-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to calculate the summation 
 *           of all elements of the linked list.
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
			perror("\n Error");
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


// Function for -> Add all elements of Linked List 
void add(struct Node *pHead)
{
	struct Node *add = pHead;
	int total = 0;

	printf("\n");
	while(add != NULL) {
		printf("%d ", add -> data);
		if(add -> next != NULL) {
			printf(" + ");
		}

		total = total + add->data;
		add = add -> next;
	}
	printf("= %d\n", total);
}


int main()
{
	struct Node *pHead;
	int num = getN();
	
	pHead = NULL;

	pHead = insertData(pHead, num);

	add(pHead); //Add all Nodes

	return 0;
}


/* =================================================================

Output :

	Enter No. of nodes you want to enter: 6

	Enter Data: 10

	Enter Data: 50

	Enter Data: 30

	Enter Data: 40

	Enter Data: 20

	Enter Data: 60
	
	10  + 50  + 30  + 40  + 20  + 60 = 210

  =================================================================*/


