

 /* ============================================================ 
 * File: p5.c
 * Copyright: 09-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 *
 * Content:    Define a structure as:
 * 			a. Vehicle Name
 * 		   	b. Vehicle Price 
 * 			c. Vehicle Type [2 / 4]
 *
 *	For 2 Wheeler, add 
 *		i.	Mileage
 *		ii. 	Type [Geared / Gearless]
 * 
 *	For 4 Wheeler, add 
 *		i.	 Usage [Auto / Manual]
 *		ii. 	Engine No.
 *		iii. 	Type [Heavy / Light]
 *
 *  Display Data for 2 and 4 wheelers seperately
 * ============================================================*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// Struct Declaration for Union "count_wheels" Starts
// Struct Declaration for two_wheeler 
struct two_wheeler {

	float  mileage;
	bool   gear; // true for gear, false for gearless

};


// Struct Declaration for four_wheeler 
struct four_wheeler {

	bool usage; // true for auto, false for manual
	char engine_no[20];
	bool weight; // true for heavy, false for light

};
// Struct Declaration for Union "count_wheels" Ends


// Main Structure Declaration Starts
struct vehicle {

	char  vehicleName[50];
	float price;
	bool  wheels; // true for 2 wheeler, false for 4 wheeler


	// Union Declaration Starts
	union count_wheels {
		struct two_wheeler;
		struct four_wheeler;
	};
	// Union Declaration Ends


};
// Main Structure Declaration Ends


// Function "inputData" for taking details of all vehicles 
struct vehicle inputData()
{
	struct vehicle v;
	int    wheels, gearType, usageType, vehicleWeight;

	static int i = 0;

	printf("\nDetails for Vehicle No: %02d\n", ++i);

	printf(" Enter Vehicle Name: ");
	scanf("%s",v.vehicleName);
	
	printf(" Enter Vehicle Price: ");
	scanf("%f",&v.price);

	while(1) {
		printf(" Enter No. of Wheels: ");
		scanf("%d",&wheels);
		// printf("size = %d\n", sizeof(wheels)); // prints 4

		if(wheels == 2) {
			v.wheels = true;
			// printf("size = %d\n", sizeof(v.wheels)); // prints 1

			printf(" Enter Mileage: ");
			scanf("%f",&v.mileage);

			printf(" Enter Gear Type \n");
			printf("  Press 1 for Geared. 0 for Gearless: ");
			scanf("%d",&gearType); 

			if(gearType) {
				v.gear = true; // Vehicle is Geared
			}

			else {
				v.gear = false; // Vehicle is Gearless
			}
			break;

		} 
		else if(wheels == 4) {
			v.wheels = false;
			// printf("size = %d\n", sizeof(v.wheels)); // prints 1

			printf(" Enter Usage \n");
			printf("  Press 1 for Auto. 0 for Manual: ");
			scanf("%d",&usageType);

			if(usageType) {
				v.usage = true; // Usage is Auto
			}

			else {
				v.usage = false; // Usage is Manual
			}

			printf(" Enter Engine No: ");
			scanf("%s",v.engine_no);

			printf(" Enter Weight \n");
			printf("  Press 1 for Heavy. 0 for Light: ");
			scanf("%d",&vehicleWeight);

			if(vehicleWeight) {
				v.weight = true; // Weight is Heavy
			}

			else {
				v.weight = false; // Weight is Light
			}

			break;
		}

		else {
			printf("Invalid no of Wheels. Try Again \n");
		}
	}

	return v;
}


// Function "displayTwoWheelers" to display 2 Wheelers only
int displayTwoWheelers(struct vehicle v)
{

	// Prints only when v.wheels is true
	// Thus, prints only 2 wheelers
	if(v.wheels) {
		printf("\n");

		printf(" Name:   %s\n", v.vehicleName);
		printf(" Price:  %0.2f\n", v.price);
		
		printf("\n");
		printf(" Mileage:   %0.2f\n",v.mileage);

		if(v.gear) { //if v.gear is true
			printf(" Gear Type: Geared\n");
		}

		else { // if v.gear is false
			printf(" Gear Type: Gearless\n");
		}

		printf("\n====================\n");
	}

	return 0;
}


// Function "displayFourWheelers" to display 4 Wheelers only
int displayFourWheelers(struct vehicle v)
{

	// Prints only when v.wheels is false
	// Thus, prints only 4 wheelers
	if(!v.wheels) {
		printf("\n");

		printf(" Name:   %s\n", v.vehicleName);
		printf(" Price:  %0.2f\n", v.price);

		printf("\n");

		if(v.usage) { // if v.usage is true
			printf(" Usage:     Auto\n");
		}

		else { // if v.usage is false
			printf(" Usage:     Manual\n");
		}

		printf(" Engine No. %s\n", v.engine_no);
		
		if(v.weight) { // if v.weight is true
			printf(" Weight:    Heavy\n");
		}

		else { // if v.weight is false
			printf(" Weight:    Light\n");
		}

		printf("\n====================\n");
	}
	return 0;
}


// Driver Program
int main()
{
	int n, i;
	struct vehicle v[50];


	// Taking Number of teams
	while(1) {
		
		printf("Enter total number of Vehicles: ");
		scanf("%d",&n);

		if(n > 0 && n < 51) {
			break;
		}

		else {
			printf("Invalid Input. Try Again\n");
		}

	}


	// Getting Data from user
	for (i = 0; i < n; ++i) {
		v[i] = inputData();
	}


	// Displaying data for 2 Wheelers 
	printf("\n\n * * * * * Two Wheelers * * * *  *\n");
	for (i = 0; i < n; ++i) {
		displayTwoWheelers(v[i]);
	}


	// Displaying data for 4 Wheelers 
	printf("\n\n * * * * * Four Wheelers * * * * *\n");
	for (i = 0; i < n; ++i) {
		displayFourWheelers(v[i]);
	}

	return 0;
}

 /* ============================================================
 * Output :
	 Enter total number of Vehicles: 10

	Details for Vehicle No: 01
	 Enter Vehicle Name: BMW
	 Enter Vehicle Price: 96387.789
	 Enter No. of Wheels: 4
	 Enter Usage
	  Press 1 for Auto. 0 for Manual: 1
	 Enter Engine No: EAF9TY
	 Enter Weight
	  Press 1 for Heavy. 0 for Light: 1

	Details for Vehicle No: 02
	 Enter Vehicle Name: HarleyDavidson
	 Enter Vehicle Price: 15354.1565
	 Enter No. of Wheels: 2
	 Enter Mileage: 8.7
	 Enter Gear Type
	  Press 1 for Geared. 0 for Gearless: 1

	Details for Vehicle No: 03
	 Enter Vehicle Name: Mercedes
	 Enter Vehicle Price: 20012
	 Enter No. of Wheels: 4
	 Enter Usage
	  Press 1 for Auto. 0 for Manual: 0
	 Enter Engine No: ABC1DE
	 Enter Weight
	  Press 1 for Heavy. 0 for Light: 0

	Details for Vehicle No: 04
	 Enter Vehicle Name: Swift
	 Enter Vehicle Price: 1560.589
	 Enter No. of Wheels: 4
	 Enter Usage
	  Press 1 for Auto. 0 for Manual: 0
	 Enter Engine No: EGJ89Y
	 Enter Weight
	  Press 1 for Heavy. 0 for Light: 0

	Details for Vehicle No: 05
	 Enter Vehicle Name: Splendor
	 Enter Vehicle Price: 1545
	 Enter No. of Wheels: 2
	 Enter Mileage: 60
	 Enter Gear Type
	  Press 1 for Geared. 0 for Gearless: 1

	Details for Vehicle No: 06
	 Enter Vehicle Name: AstonMartin
	 Enter Vehicle Price: 99878.98754
	 Enter No. of Wheels: 4
	 Enter Usage
	  Press 1 for Auto. 0 for Manual: 1
	 Enter Engine No: WER997
	 Enter Weight
	  Press 1 for Heavy. 0 for Light: 0

	Details for Vehicle No: 07
	 Enter Vehicle Name: Pulsar
	 Enter Vehicle Price: 2568.258
	 Enter No. of Wheels: 2
	 Enter Mileage: 25.265
	 Enter Gear Type
	  Press 1 for Geared. 0 for Gearless: 1

	Details for Vehicle No: 08
	 Enter Vehicle Name: Ninja
	 Enter Vehicle Price: 78965.256
	 Enter No. of Wheels: 2
	 Enter Mileage: 4.25
	 Enter Gear Type
	  Press 1 for Geared. 0 for Gearless: 0

	Details for Vehicle No: 09
	 Enter Vehicle Name: Passion
	 Enter Vehicle Price: 782.256
	 Enter No. of Wheels: 2
	 Enter Mileage: 89
	 Enter Gear Type
	  Press 1 for Geared. 0 for Gearless: 1

	Details for Vehicle No: 10
	 Enter Vehicle Name: PorscheCarerraGT
	 Enter Vehicle Price: 963879.99979
	 Enter No. of Wheels: 4
	 Enter Usage
	  Press 1 for Auto. 0 for Manual: 1
	 Enter Engine No: AJ1NK
	 Enter Weight
	  Press 1 for Heavy. 0 for Light: 1


	 * * * * * Two Wheelers * * * * *

	 Name:   HarleyDavidson
	 Price:  15354.16

	 Mileage:   8.70
	 Gear Type: Geared

	====================

	 Name:   Splendor
	 Price:  1545.00

	 Mileage:   60.00
	 Gear Type: Geared

	====================

	 Name:   Pulsar
	 Price:  2568.26

	 Mileage:   25.26
	 Gear Type: Geared

	====================

	 Name:   Ninja
	 Price:  78965.26

	 Mileage:   4.25
	 Gear Type: Gearless

	====================

	 Name:   Passion
	 Price:  782.26

	 Mileage:   89.00
	 Gear Type: Geared

	====================


	 * * * * * Four Wheelers * * * * *

	 Name:   BMW
	 Price:  96387.79

	 Usage:     Auto
	 Engine No. EAF9TY
	 Weight:    Heavy

	====================

	 Name:   Mercedes
	 Price:  20012.00

	 Usage:     Manual
	 Engine No. ABC1DE
	 Weight:    Light

	====================

	 Name:   Swift
	 Price:  1560.59

	 Usage:     Manual
	 Engine No. EGJ89Y
	 Weight:    Light

	====================

	 Name:   AstonMartin
	 Price:  99878.98

	 Usage:     Auto
	 Engine No. WER997
	 Weight:    Light

	====================

	 Name:   PorscheCarerraGT
	 Price:  963880.00

	 Usage:     Auto
	 Engine No. AJ1NK
	 Weight:    Heavy

	====================

  ============================================================*/

