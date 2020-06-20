#include <stdio.h>

void readData(int matrix[][5], int rows, int cols)
{
	int i, j;

	int (*arrptr)[5] = matrix;

	for (i = 0; i < rows; ++i) {
		printf("Enter row %d: \n", i + 1);
		
		for (j = 0; j < cols; ++j) {
			printf("Enter Col %d: ", j + 1);
			// scanf("%d",*(arrptr + (i * j) + j));
			scanf("%d",*(arrptr + i) + j);
			printf("Value: %d \n",*(*(arrptr + i) + j));
		}

	}
}

void displayData(int matrix[][5], int rows, int cols)
{
	int i, j;
	int (*arrptr)[5] = matrix;

	printf("\nMatrix Entered: \n");

	for (i = 0; i < rows; ++i) {

		for (j = 0; j < cols; ++j) {
			printf(" %3d \t",*(*(arrptr + i) + j));
		}
		printf("\n");
	}

	printf("\n");

}

void multiply(int matrix1[][5], int matrix2[][5], int rows1, int cols1, int cols2)
{
	int i, j, k, total, pdt;
	int matrix3[5][5];

	int (*arrptr1)[5] = matrix1;
	int (*arrptr2)[5] = matrix2;
	int (*arrptr3)[5] = matrix3;


	printf("\nMultiplication : \n");

	for (i = 0; i < rows1; ++i) {
		
		for (j = 0; j < cols2; ++j) {
			
			total = 0;
			
			for (k = 0; k < cols1; ++k) {
				total += *(*(arrptr1 + i) + k) * *(*(arrptr2 + k) + j);
			}

			*(*(arrptr3 + i) + j) = total;
			
		}

	}


	for (i = 0; i < rows1; i++) {

		for (j = 0; j < cols2; j++) { 

			printf ("%3d\t", *(*(arrptr3 + i) + j)); 
		} 

		printf("\n");

	} 

}

int main()
{

	int matrix1[5][5];
	int matrix2[5][5];

	int rows1, cols1, rows2, cols2;
	
	printf("Enter Rows and cols of matrix1\n");
	scanf("%d %d",&rows1, &cols1);

	printf("Enter Rows and cols of matrix1\n");
	scanf("%d %d",&rows2, &cols2);

	if(rows2 != cols1) { printf("Invalid Input \n"); }

	readData(matrix1, rows1, cols1);
	displayData(matrix1, rows1, cols1);

	readData(matrix2, rows2, cols2);
	displayData(matrix2, rows2, cols2);
	
	multiply(matrix1, matrix2, rows1, cols1, cols2);

	printf("\n");

	return 0;

}