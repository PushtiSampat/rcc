// struct1

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

		printf("\n1 |");

		pHead -> data = getData();
		pHead -> next = NULL;

		printf(" pHead: %d\n", pHead);		
		printf(" pHead -> data: %d\n", pHead -> data);
		printf(" pHead -> next: %d\n", pHead -> next);

		if(n == 1) { return pHead; }
	}

	for(i = 1; i < n; i++) {
		curr = pHead;

		printf("\n%d | \n curr: %d\n", i + 1, curr);
		printf(" pHead: %d\n", pHead);
		
		data = getData();
		
		new_node = createNode();
		
		printf("\n\tnew_node: %d\n\n", new_node);
		
		while(curr != NULL) {
			printf("\twhile(%d != NULL)\n", curr);

			if(curr -> data >= data) {
				new_node -> data = data;
				new_node -> next = curr;
				
				if(curr == pHead) {
					pHead = new_node;
				} else {
					prev -> next = new_node;
					printf("\tprev(of else): %d\n", prev);
				}

				printf("\tnew_node -> data: %d\n", new_node -> data);
				printf("\tnew_node -> next: %d\n", new_node -> next);

				printf("\tpHead: %d\n", pHead);

				break;
			} 

			prev = curr;
			printf("\tprev: %d\n\n", prev);

			curr = curr ->next;

		}

		if(curr == NULL) {

			printf("\tcurr = NULL\n");
			printf("\tprev: %d\n", prev);

			prev -> next = new_node;
			new_node -> data = data;
			new_node -> next = NULL;

			printf("\tnew_node -> data: %d\n", prev -> next);
			printf("\tnew_node -> data: %d\n", new_node -> data);
			printf("\tnew_node -> next: %d\n", new_node -> next);

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
		printf("\n \t curr: %d\n", curr);
		printf(" \t curr -> data: %d\n", curr -> data);
		printf(" \t curr -> next: %d\n", curr -> next);
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