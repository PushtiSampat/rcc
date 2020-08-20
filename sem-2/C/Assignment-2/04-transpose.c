
/* ==================================================================
Transpose using pointer
================================================================== */

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



/* ==================================================================
	Output:
	Enter Rows and cols
	3
	3
	Enter row 1:
	Enter Col 1: 10
	Value: 10
	Enter Col 2: 20
	Value: 20
	Enter Col 3: 30
	Value: 30
	Enter row 2:
	Enter Col 1: 40
	Value: 40
	Enter Col 2: 50
	Value: 50
	Enter Col 3: 60
	Value: 60
	Enter row 3:
	Enter Col 1: 70
	Value: 70
	Enter Col 2: 80
	Value: 80
	Enter Col 3: 90
	Value: 90

	Matrix Entered:
	10       20      30
	40       50      60
	70       80      90

	Output:
	10       40      70
	20       50      80
	30       60      90
================================================================== */
