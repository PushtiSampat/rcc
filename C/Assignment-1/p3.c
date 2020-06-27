

 /* ============================================================ 

 * File: p2.c
	DEFINE :
	3.	 Write a program that stores and displays the records of the customer.
	 	 The following information for account of the customer is to be stored.
		 Account no, account type, name, old balance, new balance,
		 last payment, date of last payment.
		 
		 Take structure for storing the date 
		 in days, months and year. 
		 
		 Also display the current account status by comparing 
		 current payment and previous balance.
		 
		 Also calculate the current balance by subtracting
		 the current payment from the previous balance.

 * ============================================================*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int dd,mm,yy;
} date;

typedef struct {
	int acc_no;
	float old_balance,new_balance,last_payment;
	char name[15];
	char status[10];
	date dateofpay;
} customer;

customer getData();
void setPrint(customer[],int); 
void menudriven(customer[],int);


customer getData()
{
	customer s;
	
	printf("\nEnter Account Number : ");
	scanf("%d",&s.acc_no);
	
	printf("Enter The Customer's Name : ");
	scanf("%s",s.name);
	
	printf("Enter The Old Balance : ");
	scanf("%f",&s.old_balance);
	
	printf("Enter The Last Payment : ");
	scanf("%f",&s.last_payment);
	
	s.new_balance = s.old_balance - s.last_payment;
	
	if(s.new_balance > 0)
		strcpy(s.status,"Pending");
	else
		strcpy(s.status,"Clear");

	printf("Enter Date of Last Payment [dd mm yy] : ");
	scanf("%d %d %d",&s.dateofpay.dd,&s.dateofpay.mm,&s.dateofpay.yy);
	printf(" ========== ");
	return s;
}

void setPrint(customer s[],int tc)
{
	int i;
	printf("\n\tList Of Customers\n ========== ");
	for( i = 0; i < tc; i++ )
	{
		printf("\n\n\tId: %d \n\tName: %s\n\tOld Bal: %.2f\n\tLast Payment: %.2f\n\tLast Pymnt Dt: %d/%d/%d\n\tNew Bal. = %.2f\n ========== ",s[i].acc_no,s[i].name,s[i].old_balance,s[i].last_payment,s[i].dateofpay.dd,s[i].dateofpay.mm,s[i].dateofpay.yy,s[i].new_balance);
	}
}

void menudriven(customer s[],int tc)
{
	int i,j,option,check;
	char name[15];
	
	printf("\n\n1: Disp Customer Details\n2: Find Customer By Name\n3: Disp Status\n4: Display Curr Bal.\n5: Exit\n\n");
	scanf("%d",&option);
	
	if(option == 1) {
		setPrint(s,tc);
		menudriven(s,tc);
	}

	else if(option == 2) {
		printf("Enter Customer Name : ");
		scanf("%s",name);
		for( i = 0; i < tc; i++ ) {
			check = strcmp(s[i].name,name);
			if( check == 0 )
				printf("\n\n\tCustomer Id = %d \n\tCustomer Name = %s\n\tOld Balance = %.2f\n\tLast Payment = %.2f\n\tLast Payment Date = %d/%d/%d\n\tNew Balance = %.2f \n\tStatus = %s \n\n ========== ",s[i].acc_no,s[i].name,s[i].old_balance,s[i].last_payment,s[i].dateofpay.dd,s[i].dateofpay.mm,s[i].dateofpay.yy,s[i].new_balance,s[i].status);
		}
		menudriven(s,tc);
	}

	else if(option == 3) {
		for( i = 0; i < tc; i++ )
			printf("\nCustomer Name = %s\n Status = %s\n ========== ",s[i].name,s[i].status);
		menudriven(s,tc);
	}

	else if(option == 4) {
		for( i = 0; i < tc; i++ ) 
			printf("\nCustomer Name = %s\n Current Balance = %.2f\n ========== ",s[i].name,s[i].new_balance);
		menudriven(s,tc);
	}

	else if(option == 5) {
		exit(0);	
	}

	else {
		printf("Invalid Option");
		menudriven(s,tc);
	}

	printf("\nNo such Customer\n");

	menudriven(s,tc);
}


int main()
{
	customer c[50];
	int i,total_cust;
	printf("Enter Number of Customers: ");
	scanf("%d",&total_cust);
	for( i = 0; i < total_cust; i++ )
	{
		c[i] = getData();
	}

	setPrint(c,total_cust);
	menudriven(c,total_cust);

	return 0;
}



/* ============================================================ 
 * Output :


	Enter Number of Customers: 3

	Enter Account Number : 10
	Enter The Customer's Name : Ajinkya
	Enter The Old Balance : 5000
	Enter The Last Payment : 5000
	Enter Date of Last Payment [dd mm yy] : 12 12 12
	 ==========
	Enter Account Number : 20
	Enter The Customer's Name : Pradip
	Enter The Old Balance : 10000
	Enter The Last Payment : 1200
	Enter Date of Last Payment [dd mm yy] : 5 8 13
	 ==========
	Enter Account Number : 30
	Enter The Customer's Name : Nirav
	Enter The Old Balance : 5600
	Enter The Last Payment : 5700
	Enter Date of Last Payment [dd mm yy] : 26 1 14
	 ==========
	        List Of Customers
	 ==========

	        Id: 10
	        Name: Ajinkya
	        Old Bal: 5000.00
	        Last Payment: 5000.00
	        Last Pymnt Dt: 12/12/12
	        New Bal. = 0.00
	 ==========

	        Id: 20
	        Name: Pradip
	        Old Bal: 10000.00
	        Last Payment: 1200.00
	        Last Pymnt Dt: 5/8/13
	        New Bal. = 8800.00
	 ==========

	        Id: 30
	        Name: Nirav
	        Old Bal: 5600.00
	        Last Payment: 5700.00
	        Last Pymnt Dt: 26/1/14
	        New Bal. = -100.00
	 ==========

	1: Disp Customer Details
	2: Find Customer By Name
	3: Disp Status
	4: Display Curr Bal.
	5: Exit

	1

	        List Of Customers
	 ==========

	        Id: 10
	        Name: Ajinkya
	        Old Bal: 5000.00
	        Last Payment: 5000.00
	        Last Pymnt Dt: 12/12/12
	        New Bal. = 0.00
	 ==========

	        Id: 20
	        Name: Pradip
	        Old Bal: 10000.00
	        Last Payment: 1200.00
	        Last Pymnt Dt: 5/8/13
	        New Bal. = 8800.00
	 ==========

	        Id: 30
	        Name: Nirav
	        Old Bal: 5600.00
	        Last Payment: 5700.00
	        Last Pymnt Dt: 26/1/14
	        New Bal. = -100.00
	 ==========

	1: Disp Customer Details
	2: Find Customer By Name
	3: Disp Status
	4: Display Curr Bal.
	5: Exit

	2
	Enter Customer Name : Nirav


	        Customer Id = 30
	        Customer Name = Nirav
	        Old Balance = 5600.00
	        Last Payment = 5700.00
	        Last Payment Date = 26/1/14
	        New Balance = -100.00
	        Status = Clear

	 ==========

	1: Disp Customer Details
	2: Find Customer By Name
	3: Disp Status
	4: Display Curr Bal.
	5: Exit

	3

	Customer Name = Ajinkya
	 Status = Clear
	 ==========
	Customer Name = Pradip
	 Status = Pending
	 ==========
	Customer Name = Nirav
	 Status = Clear
	 ==========

	1: Disp Customer Details
	2: Find Customer By Name
	3: Disp Status
	4: Display Curr Bal.
	5: Exit

	4

	Customer Name = Ajinkya
	 Current Balance = 0.00
	 ==========
	Customer Name = Pradip
	 Current Balance = 8800.00
	 ==========
	Customer Name = Nirav
	 Current Balance = -100.00
	 ==========

	1: Disp Customer Details
	2: Find Customer By Name
	3: Disp Status
	4: Display Curr Bal.
	5: Exit

	5


 ============================================================ */ 


