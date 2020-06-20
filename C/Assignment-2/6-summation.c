#include <stdio.h>

void readData(int matrix[][5], int rows, int cols)
{
	int i, j;

	int (*arrptr)[5] = matrix;

	for (i = 0; i < rows; ++i) {
		printf("\nEnter row %d: \n", i + 1);
		
		for (j = 0; j < cols; ++j) {
			printf("Enter Col %d: ", j + 1);
			scanf("%d",*(arrptr + i) + j);
		}

	}
}

void displayData(int matrix[][5], int rows, int cols)
{
	int i, j, rowTotal, colTotal;
	int (*arrptr)[5] = matrix;

	printf("\nMatrix Entered: \n");

	for (i = 0; i < rows; ++i) {

		rowTotal = 0;
		for (j = 0; j < cols; ++j) {
			rowTotal += *(*(arrptr + i) + j);
			printf(" %3d \t",*(*(arrptr + i) + j));
		}
		printf("| %d\n", rowTotal);
	}

	for (i = 0; i <= cols; ++i) {
		printf(" --- \t");
	}

	printf("\n");

	for (i = 0; i < cols; ++i) {
		
		colTotal = 0;
		for (j = 0; j < rows; ++j) {
			colTotal += *(*(arrptr + j) + i);
		}

		printf(" %3d \t", colTotal);
	}

	printf("\n");

}

void sum(int matrix[][5], int rows, int cols)
{
	int i, j, total = 0;

	int (*arrptr)[5] = matrix;

	for (i = 0; i < rows; ++i) {
		
		for (j = 0; j < cols; ++j) {
			total = total + *(*(arrptr + i) + j);	
		}

	}

	printf("\nAddition : %d\n", total);

}

int main()
{

	int matrix[5][5];

	int rows, cols;
	
	printf("Enter Rows and cols of matrix1\n");
	scanf("%d %d",&rows, &cols);

	readData(matrix, rows, cols);
	displayData(matrix, rows, cols);
	
	sum(matrix, rows, cols);

	printf("\n");

	return 0;

}