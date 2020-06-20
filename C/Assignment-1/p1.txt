 /* ===========================================================
 * File:      p1.c
 * Copyright: 08-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:   Define a structure called Criket as:
 * 		   	a. Player Name 
 * 			b. Team Name
 * 			c. Batting Average
 * 		
 *  	Declare player with 50 elements. Read data and display  
 *      team wise name of players with their batting avg.
 * ========================================================== */

// Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>

// Structure Declaration
struct cricket {
	char   teamName[50];
	char   playerName[50];
	float  average;
};

// Function inputData returing Strcuture of Cricket
struct cricket inputData()
{
	struct cricket c;
	static int count = 1;

	printf("\n Team %d \n", count++);
 
	printf(" Enter Team Name: ");
	scanf("%s",c.teamName);

	printf(" Enter Player Name: ");
	scanf("%s",c.playerName);

	printf(" Enter Batting Avg: ");
	scanf("%f",&c.average);

	return c; //Returing Entire Structure
}

// Function quicksortByTeamname
void quicksortByTeamname(struct cricket c[], int l, int r)
{
	struct cricket temp;	
	char   pivot[50]; 
	int    i, cnt;

	if (l >= r) { return; }

	strcpy(pivot, c[r].teamName);
	cnt = l;

	for (i = l; i <= r; i++) {
		if (strcmp(c[i].teamName, pivot) <= 0) {

			// Swapping Strucutre
			temp = c[i];
			c[i] = c[cnt];
			c[cnt] = temp;
			// Swapping Strucutre Ends

			cnt++;
		}
	}

	quicksortByTeamname(c, l, cnt - 2);
	quicksortByTeamname(c, cnt, r);
}

// Function sortTeamThenAverage for Descending Sort according to Average
void sortTeamThenAverage(struct cricket c[], int num)
{
	struct cricket temp;
	int i, j, count = 1, index = 1, while_loop = 1;
	char tempTeam[50];

	while(while_loop) {
		strcpy(tempTeam, c[index].teamName);

		for(i = index; i < num; i++) {
			
			if(strcmp(tempTeam, c[i].teamName) == 0) {
				count++;
			}
			else{ break; }

		}

		// Performing Bubble Sort for Average of Players
		for(i = index - 1; i < count - 1; i++) {
			for(j = index - 1; j < count - 1; j++) {

				if(c[j].average < c[j + 1].average) {

					// Swapping Strucutre
					temp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = temp;	
					// Swapping Strucutre Ends

				}

			}
		}
		// Bubble Sort Over

		count++;
		index = count;

		// Stop the loop if count exceeds number of teams
		if(num <= count) {
			while_loop = 0;
		}

	}
}

// Function to display final result
int displaySortedData(struct cricket c[], int num)
{
	int i = 0, j;
	struct cricket temp	;

	// Function to sort by Team Name 
	quicksortByTeamname(c, 0, num - 1);

	// Function to sort by Average 
	sortTeamThenAverage(c, num);

	// Diplaying Data for 1st team
	printf(" * * * Team %s * * * \n", c[i].teamName);
	printf("  \tPlayer  :  %s\n",      c[i].playerName);
	printf("  \tAverage :  %.2f\n\n",  c[i].average);
	
	// Diplaying Data for rest of team
	for(i = 1; i < num; i++) {

		if(strcmp(c[i].teamName, c[i - 1].teamName) != 0) {
			printf(" * * * Team %s * * * \n", c[i].teamName);
		}

		printf("  \tPlayer  :  %s\n",     c[i].playerName);
		printf("  \tAverage :  %.2f\n\n", c[i].average);
	}
	
	return 0;
}

// Driver Program 
int main()
{
	int    n, i;
	struct cricket c[50];

	while(1) {
		printf("Enter total number of teams: ");
		scanf("%d",&n);
		if(n > 0 && n < 51) { break; } 
		else {
			printf("Invalid Input. Try Again\n");
		}
	}

	// Getting Data from user
	for(i = 0; i < n; ++i) {
		c[i] = inputData();
	}

	// Displaying Data
	displaySortedData(c, n);

	return 0; 
}



/* =================================================================
* Output :

	Enter total number of teams: 10

	 Team 1
	 Enter Team Name: csk
	 Enter Player Name: Dhaval
	 Enter Batting Avg: 55

	 Team 2
	 Enter Team Name: dd
	 Enter Player Name: Kohli
	 Enter Batting Avg: 89

	 Team 3
	 Enter Team Name: mi
	 Enter Player Name: Ajinkya
	 Enter Batting Avg: 100

	 Team 4
	 Enter Team Name: csk
	 Enter Player Name: askdka
	 Enter Batting Avg: 45

	 Team 5
	 Enter Team Name: csk
	 Enter Player Name: askhdgsa
	 Enter Batting Avg: 47

	 Team 6
	 Enter Team Name: mi
	 Enter Player Name: askjdhskaj
	 Enter Batting Avg: 78

	 Team 7
	 Enter Team Name: mi
	 Enter Player Name: Yash
	 Enter Batting Avg: 85

	 Team 8
	 Enter Team Name: dd
	 Enter Player Name: Nirav
	 Enter Batting Avg: 95

	 Team 9
	 Enter Team Name: dd
	 Enter Player Name: Pradip
	 Enter Batting Avg: 67

	 Team 10
	 Enter Team Name: csk
	 Enter Player Name: Ghanshyam
	 Enter Batting Avg: 70

	 * * * Team csk * * *
		 Player  : Ghanshyam
		 Average : 70.00

		 Player  : Dhaval
		 Average : 55.00

		 Player  : askhdgsa
		 Average : 47.00

		 Player  : askdka
		 Average : 45.00

	 * * * Team dd * * *
		 Player  : Nirav
		 Average : 95.00

		 Player  : Kohli
		 Average : 89.00

		 Player  : Pradip
		 Average : 67.00

	 * * * Team mi * * *
		 Player  : Ajinkya
		 Average : 100.00

		 Player  : Yash
		 Average : 85.00

		 Player  : askjdhskaj
		 Average : 78.00 
=================================================================*/ 