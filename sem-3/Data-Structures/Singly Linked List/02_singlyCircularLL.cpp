#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 2
int size = 0;

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
		printf("******************"); 
	}
	printf("\n");
}


// Function for -> Couting Nodes
int countNodes(struct Node *head)
{
	int count = 0;
	struct Node* curr = head;

	if(head == NULL){
		return 0;
	}
	do{
		count ++;
		curr = curr-> next;		
	}while (head != curr);

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

	printf(" * Addr. *");
	do{
		printf(" %14d * ", curr);
		curr = curr -> next;
	}while(pHead != curr);

	printStylish(count);
	curr = pHead;

	printf(" * Index *");
	do{
		printf(" %14d * ", ++i);
		curr = curr -> next;
	}while(pHead != curr);

	printStylish(count);
	curr = pHead;

	printf(" * Data  *");
	do{
		printf(" %14d * ", curr -> data);
		curr = curr -> next;
	}while(pHead != curr);

	printStylish(count);
	curr = pHead;

	printf(" * Next  *");
	do{
		printf(" %14d * ", curr -> next);
		curr = curr -> next;
	}while(pHead != curr);

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
	struct Node *curr = *pHead;

	new_node->data = data;
	new_node->next = *pHead;

	while(curr->next != *pHead) {
		curr = curr->next;
	}

	curr->next = new_node;

	return;
}


void insertAtStart(struct Node **pHead, int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *curr = *pHead;

	new_node->data = data;
	new_node->next = *pHead;

	while(curr->next != *pHead) {
		curr = curr->next;
	}

	*pHead = new_node;
	curr -> next = *pHead;

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

	printf("\n Which Index do you want to remove: ");
	scanf("%d",&index);

	if(index > 0 && index <= count) { 
		return index;
	}
	printf("Enter valid Index\n");
	n = askIndexToDel(count);	
}


void insertAtSpecific(struct Node **pHead, int data)
{
	int position, index, i = 0;
	struct Node *curr = *pHead;
	struct Node *temp;
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	display(*pHead);
	index = askIndex(countNodes(*pHead));


	do{

		if(++i == index) {

			new_node -> data = data;

			if(curr -> next == *pHead) {
				curr -> next = new_node;
				new_node -> next = *pHead;
			} 

			else {
				temp = curr -> next;
				curr -> next = new_node;
				new_node -> next = temp;
			}

		}	

		curr = curr -> next	;

	}while (curr != *pHead);

}


static void remove(struct Node **pHead)
{
	int position, index, i = 0, count;
	struct Node *curr = *pHead;
	struct Node *prev = NULL;
	if(*pHead == NULL || size <= 0) {
		printf("-Stack Underflow");
		return;
	}
	display(*pHead);

	count = countNodes(*pHead);
	index = askIndexToDel(count);

	do{

		if(++i == index) {

			if(i == 1) {

				if(count == 1) {
					free(*pHead);
					*pHead = NULL;
					printf("\n\t *** Index Deleted *** \n");
					size--;
					return;
				}

				else {

					while(curr -> next != *pHead){
						curr = curr ->  next;
					}

					*pHead = (*pHead) -> next;
					curr -> next = *pHead;

					free(curr);
					printf("\n\t *** Index Deleted *** \n");
					size--;
					return;
				}

			}

			else {

				if(curr -> next == *pHead) {
					free(curr);
					prev -> next = *pHead;
					printf("\n\t *** Index Deleted *** \n");
					size--;
					return;
				}

				else {
					prev -> next = curr -> next;
					free(curr);
					printf("\n\t *** Index Deleted *** \n");
					size--;
					return;
				}

			}

		}	

		prev = curr;
		curr = curr -> next	;

	}while (curr != *pHead);

}


void insert(struct Node **pHead, int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	int insertChoice;

	if(size >= CAPACITY){
		printf("-Stack Overflow\n");
		return;
	}

	// If linked List is empty 
	if(*pHead == NULL) {
		*pHead = new_node;
		new_node->data = data;
		new_node->next = new_node;
		display(*pHead);
		size++;
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
		remove(&(*pHead));
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

	while((choice = askChoice())){
		doTask(&pHead, choice);
	}

	return 0;
}
