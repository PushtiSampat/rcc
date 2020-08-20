

 /* ============================================================ 
 * File: p4.c
 * Copyright: 09-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 *
 * Content:    Define a structure as:
 * 			a. Author
 * 		   	b. Title 
 * 			c. Price
 * 			d. Publisher
 * 			e. Stock Position
 *
 * ============================================================*/


#include <stdio.h>
#include <string.h>

// Main Structure Declaration Starts
struct books {

	char author[50];
	char title[50];
	float price;
	char publisher[50];
	int stock;

};
// Main Structure Declaration Ends


// Function "inputData" for taking details of all Books
void inputData(struct books b[], int n)
{
	int i;

	for (i = 0; i < n; ++i) {

		printf("\n ========== Details of Books : %d ========== \n", i + 1);

		printf("\nEnter Name of Author\n");
		scanf("%s",b[i].author);

		printf("\nEnter Title of Book\n");
		scanf("%s",b[i].title);

		printf("\nEnter price of Book\n");
		scanf("%f",&b[i].price);

		printf("\nEnter name of Publisher\n");
		scanf("%s",b[i].publisher);

		printf("\nEnter Stock\n");
		scanf("%d",&b[i].stock);

	}
} 

void searchBook(struct books b[], int n)
{

	int i, j, copies, authorFound = 0, titleFound = 0;
	char tempAuthor[50], tempTitle[50];
	float amt;

	printf("\n ========== Search any Book ========== \n");

	printf("\nEnter Author Name : ");
	scanf("%s",tempAuthor);

	for(i = 0; i < n; ++i) {

		// Checking if author exists
		if(strcmp(b[i].author, tempAuthor) == 0) {

			authorFound = 1;

			printf("\nEnter Book Title : ");
			scanf("%s",tempTitle);

			// Checking if such Book Title exists
			if(strcmp(b[i].title, tempTitle) == 0) {

				titleFound = 1;

				printf("\nEnter Number of Copies You Want : ");
				scanf("%d",&copies);

				if(b[i].stock >= copies)  {

					amt = b[i].price * copies; // Bill amount

					printf("\n\tTotal Payable Amount For %d Copies Will Be :\n", copies);
					printf("\t[%.2f x %d] = $ %.2f\n", b[i].price, copies, amt);

				}

				// when available copies are less than demanded  
				else {
					printf("Out of Stock\n");
				}

			}
		}
	}

	// if no such author exists
	if(!authorFound) {
		printf("< %s > author not found in list\n", tempAuthor);
	}

	// if so such book title exists
	else if(!titleFound) {
		printf("< %s > has no such book as < %s >\n", tempAuthor, tempTitle);
	}
}


// Driver Program
int main()
{
	int n, i;
	struct books b[50];

	// Taking Number of Books
	while(1) {
		
		printf("Enter no of books: ");
		scanf("%d",&n);
		
		if(n > 0 && n < 51) {
			break;
		}

		else {
			printf("Invalid Input. Try Again\n");
		}

	}

	// Getting data for books 
	inputData(b, n);
	
	// Search any book you want
	searchBook(b, n);

	return 0;
}



 /* ============================================================
 * Output :

	Enter no of books: 4

	 ========== Details of Books : 1 ==========

	Enter Name of Author
	Ajinkya

	Enter Title of Book
	Python

	Enter price of Book
	2601

	Enter name of Publisher
	Ghanshyam

	Enter Stock
	812

	 ========== Details of Books : 2 ==========

	Enter Name of Author
	Lakshya

	Enter Title of Book
	Kierra

	Enter price of Book
	521.125

	Enter name of Publisher
	Advani

	Enter Stock
	125

	 ========== Details of Books : 3 ==========

	Enter Name of Author
	Balaguruswamy

	Enter Title of Book
	C

	Enter price of Book
	256.85

	Enter name of Publisher
	Hills

	Enter Stock
	71

	 ========== Details of Books : 4 ==========

	Enter Name of Author
	Devangi

	Enter Title of Book
	Riverfront

	Enter price of Book
	999.99

	Enter name of Publisher
	Pabari

	Enter Stock
	99

	 ========== Search any Book ==========

	Enter Author Name : Balaguruswamy

	Enter Book Title : C

	Enter Number of Copies You Want : 25

	        Total Payable Amount For 25 Copies Will Be :
	        [256.85 x 25] = $ 6421.25

  ============================================================*/

