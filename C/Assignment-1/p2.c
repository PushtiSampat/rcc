

 /* ============================================================ 
 * File: p2.c
 * Copyright: 09-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 *
 * Content:    Define a structure as:
 * 			a. Team Name
 * 		   	b. City Name 
 * 			c. No. of Wins
 *
 *	For Baseball Team, add 
 *		i.	No. of Hits
 *		ii. 	no. of runs
 *		iii. 	no. of errors
 *		iv. 	no. of extra timing games
 * 
 *	For Baseball Team, add 
 *		i.	 No. of Ties
 *		ii. 	no. of Goals
 *		iii. 	no. of Touch Downs
 *		iv. 	no. of Turnovers
 *
 *     Display Data for Baseball and Football seperately
 *     Also display data sorted by highest no. of wins
 * ============================================================*/
#include <stdio.h>
#include <string.h>

// Struct Declaration for Union "game" Starts
// Struct Declaration for Baseball
struct baseball{
	int hits;
	int runs;
	int errors;
	int extra_timing_games;
};

// Struct Declaration for Football
struct football {
	int ties;
	int goals;
	int touchdowns;
	int turn_overs;
};
// Struct Declaration for Union "game" Ends

// Main Structure Declaration Starts
struct team {
	char teamName[50];
	char city[50];
	int  wins;
	int  option;

	// Union Declaration Starts
	union game {
		struct baseball;
		struct football;
	};
	// Union Declaration Ends

};
// Main Structure Declaration Ends

// Function "inputData" for taking details of all teams 
struct team inputData()
{
	struct team t;
	union  game g;

	static int count = 1;

	printf("\n Team %d \n", count++);

	printf(" Enter Team Name: ");
	scanf("%s",t.teamName);

	printf(" Enter City Name: ");
	scanf("%s",t.city);

	printf(" Enter Wins: ");
	scanf("%d",&t.wins);

	// Selecting Game. Baseball or Football
	while(1) {
		printf("Which game this team plays?. Choose option \n");

		printf("\t1. Baseball  \n");
		printf("\t2. Football  \n");
		
		scanf("%d",&t.option);

		if(t.option == 1 || t.option == 2) {
			break;
		} else {
			printf("\nInvalid Input. Try Again\n");
		}

	}
	// Selecting Game Ends

	// Details required for Baseball
	if(t.option == 1) {
		printf(" Enter Hits: ");
		scanf("%d",&t.hits);

		printf(" Enter Runs: ");
		scanf("%d",&t.runs);

		printf(" Enter Errors: ");
		scanf("%d",&t.errors);

		printf(" Enter Extra Timing Games: ");
		scanf("%d",&t.extra_timing_games);		
	}
	// Details for Baseball Ends

	// Details required for Football
	 else {
		printf(" Enter Ties: ");
		scanf("%d",&t.ties);

		printf(" Enter goals: ");
		scanf("%d",&t.goals);

		printf(" Enter Touchdowns: ");
		scanf("%d",&t.touchdowns);

		printf(" Enter Turn Overs: ");
		scanf("%d",&t.turn_overs);
	}
	// Details for Football Ends

	return t;
}


// Function "displayBaseball" to display Baseball Teams only
int displayBaseball(struct team t)
{
	static int count = 1;

	// option 1 is for baseball, so checking "1" 
	if (t.option == 1) {
		printf("\n\n ===Team %d=== \n", count++);

		printf(" Team Name: %s\n", t.teamName);
		printf(" City:      %s\n", t.city);
		printf(" Wins:      %d\n", t.wins);

		printf("\n");
		
		printf(" Hits:        %d \n", t.hits);
		printf(" Runs:        %d \n", t.runs);
		printf(" Errors:      %d \n", t.errors);
		printf(" Extra Games: %d \n",t.extra_timing_games);

	}
	return 0;
}

// Function "displayFootball" to display Football Teams only
int displayFootball(struct team t)
{
	static int count = 1;

	// option 2 is for football, so checking "2" 
	if (t.option == 2) {
		printf("\n\n ===Team %d=== \n", count++);

		printf(" Team Name: %s\n", t.teamName);
		printf(" City:      %s\n", t.city);
		printf(" Wins:      %d\n", t.wins);

		printf("\n");

		printf(" Ties:        %d \n", t.ties);
		printf(" Goals:       %d \n", t.goals);
		printf(" Touchdowns:  %d \n", t.touchdowns);
		printf(" Turnovers:   %d \n", t.turn_overs);

	}
	return 0;
}

// Function "quicksortByWins" for sorting Teams by 
// highest no. of wins
void quicksortByWins(struct team c[], int l, int r)
{
	struct team temp;	
	int pivot;
	int i, cnt;

	if (l >= r) { return; }

	pivot =  c[r].wins;
	cnt = l;

	for (i = l; i <= r; i++) {
		if (c[i].wins >= pivot) {

			// Swapping Structure Starts
			temp = c[i];
			c[i] = c[cnt];
			c[cnt] = temp;
			// Swapping Structure Ends

			cnt++; 
		}
	}

	quicksortByWins(c, l, cnt - 2);
	quicksortByWins(c, cnt, r);
}


// Driver Program
int main()
{
	int n, i;
	struct team t[50];

	// Taking Number of teams
	while(1) {
		printf("Enter total number of teams: ");
		scanf("%d",&n);
		if(n > 0 && n < 51) {
			break;
		} else {
			printf("Invalid Input. Try Again\n");
		}
	}

	// Getting Data from user
	for (i = 0; i < n; ++i) {
		t[i] = inputData();
	}
	
	// Sorting Teams according to Highest Wins First
	quicksortByWins(t, 0, n - 1);

	// Displaying data for Baseball Team 
	printf("\n\n\n * * * Baseball Team * * *");
	for (i = 0; i < n; ++i) {
		displayBaseball(t[i]);
	}

	// Displaying data for Football Team 
	printf("\n\n\n * * * Football Team * * *");
	for (i = 0; i < n; ++i) {
		displayFootball(t[i]);
	}

	return 0;
}

/* ============================================================ 
 * Output :
	Enter total number of teams: 10

	 Team 1
	 Enter Team Name: Tigers
	 Enter City Name: Banglore
	 Enter Wins: 10
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 12
	 Enter Runs: 120
	 Enter Errors: 2
	 Enter Extra Timing Games: 2

	 Team 2
	 Enter Team Name: Lions
	 Enter City Name: Hydrabad
	 Enter Wins: 12
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	2
	 Enter Ties: 1
	 Enter goals: 22
	 Enter Touchdowns: 2
	 Enter Turn Overs: 8

	 Team 3
	 Enter Team Name: Warriors
	 Enter City Name: Ahmedabad
	 Enter Wins: 55
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	2
	 Enter Ties: 4
	 Enter goals: 102
	 Enter Touchdowns: 33
	 Enter Turn Overs: 42

	 Team 4
	 Enter Team Name: Winners
	 Enter City Name: Delhi
	 Enter Wins: 12
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 10
	 Enter Runs: 20
	 Enter Errors: 30
	 Enter Extra Timing Games: 40

	 Team 5
	 Enter Team Name: Savers
	 Enter City Name: Mumbai
	 Enter Wins: 33
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 23
	 Enter Runs: 12
	 Enter Errors: 2
	 Enter Extra Timing Games: 1

	 Team 6
	 Enter Team Name: Wellingtons
	 Enter City Name: Kolkatta
	 Enter Wins: 88
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 33
	 Enter Runs: 22
	 Enter Errors: 0
	 Enter Extra Timing Games: 7

	 Team 7
	 Enter Team Name: Heroes
	 Enter City Name: Pune
	 Enter Wins: 45
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	2
	 Enter Ties: 12
	 Enter goals: 44
	 Enter Touchdowns: 33
	 Enter Turn Overs: 22

	 Team 8
	 Enter Team Name: Unity
	 Enter City Name: Kochi
	 Enter Wins: 77
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 66
	 Enter Runs: 55
	 Enter Errors: 44
	 Enter Extra Timing Games: 33

	 Team 9
	 Enter Team Name: PenPencil
	 Enter City Name: Gandhidham
	 Enter Wins: 108
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	2
	 Enter Ties: 0
	 Enter goals: 1008
	 Enter Touchdowns: 0
	 Enter Turn Overs: 1

	 Team 10
	 Enter Team Name: Best
	 Enter City Name: Raipur
	 Enter Wins: 2
	Which game this team plays?. Choose option
	        1. Baseball
	        2. Football
	1
	 Enter Hits: 12
	 Enter Runs: 13
	 Enter Errors: 55
	 Enter Extra Timing Games: 33



	 * * * Baseball Team * * *

	 ===Team 1===
	 Team Name: Wellingtons
	 City:      Kolkatta
	 Wins:      88

	  Hits:        33   
	  Runs:        22   
	  Errors:      0   
	  Extra Games: 7

	 ===Team 2===
	 Team Name: Unity
	 City:      Kochi
	 Wins:      77

	  Hits:        66   
	  Runs:        55   
	  Errors:      44   
	  Extra Games: 33

	 ===Team 3===
	 Team Name: Savers
	 City:      Mumbai
	 Wins:      33

	  Hits:        23   
	  Runs:        12   
	  Errors:      2   
	  Extra Games: 1

	 ===Team 4===
	 Team Name: Winners
	 City:      Delhi
	 Wins:      12

	  Hits:        10   
	  Runs:        20   
	  Errors:      30   
	  Extra Games: 40

	 ===Team 5===
	 Team Name: Tigers
	 City:      Banglore
	 Wins:      10

	  Hits:        12   
	  Runs:        120   
	  Errors:      2   
	  Extra Games: 2

	 ===Team 6===
	 Team Name: Best
	 City:      Raipur
	 Wins:      2

	  Hits:        12   
	  Runs:        13   
	  Errors:      55   
	  Extra Games: 33


	 * * * Football Team * * *

	 ===Team 1===
	 Team Name: PenPencil
	 City:      Gandhidham
	 Wins:      108

	 Ties:        0   
	 Goals:       1008   
	 Touchdowns:  0   
	 Turnovers:   1

	 ===Team 2===
	 Team Name: Warriors
	 City:      Ahmedabad
	 Wins:      55

	 Ties:        4   
	 Goals:       102   
	 Touchdowns:  33   
	 Turnovers:   42

	 ===Team 3===
	 Team Name: Heroes
	 City:      Pune
	 Wins:      45

	 Ties:        12   
	 Goals:       44   
	 Touchdowns:  33   
	 Turnovers:   22

	 ===Team 4===
	 Team Name: Lions
	 City:      Hydrabad
	 Wins:      12

	 Ties:        1   
	 Goals:       22   
	 Touchdowns:  2   
	 Turnovers:   8

============================================================ */ 

