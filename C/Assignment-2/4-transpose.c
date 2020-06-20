#include <stdio.h>

void readData(int matrix[][5], int rows, int cols)
{
	int i, j;

	int (*arrptr)[5] = matrix;

	for (i = 0; i < rows; ++i) {
		printf("Enter row %d: \n", i + 1);
		
		for (j = 0; j < cols; ++j) {
			printf("Enter Col %d: ", j + 1);
			// scanf("%d",arrptr + (i * j) + j);
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
			printf("%d \t ",*(*(arrptr + i) + j));
		}

		printf("\n");
	}
}

void transpose(int matrix[][5], int rows, int cols)
{
	int i, j;
	int (*arrptr)[5] = matrix;

	printf("\nOutput: \n");

	for (i = 0; i < cols; ++i) {
		
		for (j = 0; j < rows; ++j) {
			printf("%d \t ",*(*(arrptr + j) + i));
		}

		printf("\n");
	}
}

int main()
{
	int matrix[5][5];
	int rows, cols;
	
	printf("Enter Rows and cols\n");
	scanf("%d %d",&rows, &cols);

	if(rows > 5 || cols > 5) {
		printf("Invalid Input \n");
		// exit(0);
	}

	readData(matrix, rows, cols);
	displayData(matrix, rows, cols);
	transpose(matrix, rows, cols);

	printf("\n");
}