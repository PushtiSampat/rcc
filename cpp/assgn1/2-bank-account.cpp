#include<iostream>

using namespace std;

class BankAccount
{
	private :
	static int count;
	int id;
	int balance = 0;

	public :
	BankAccount()
	{
		id = count++;
	}

	int askChoice();
	void display();
	void deposit();
	void withdraw();
	void task(int);
};

int BankAccount :: askChoice()
{
	int choice = 0;
	
	while (!choice) { 
		cout << endl << " =========Enter Choice=========== \n\n";
		cout << "\n\nEnter your choice" << endl << " 1. Check balance" << endl <<" 2. Deposit" << endl
		<< " 3. Withdraw" << endl;

		cin >> choice;
		
		if(choice < 1 || choice > 3) {

			cout << endl << " *** Invalid Choice *** ";
			cout << endl << " * T R Y _ A G A I N * ";
			choice = 0;
		}
	}

	return choice;
}

int askAccountId()
{ 
	int accountId;
	cout << endl << "Enter your accountId: ";
	cin >> accountId;
	if(accountId < 1 || accountId > 10) {
		cout << endl << " *** Invalid Id *** ";
		cout << endl << " * T R Y _ A G A I N * ";
		accountId = askAccountId();
	}
	return accountId;
}

void BankAccount :: display()
{
	cout << endl;
	cout << endl << " ==========Bank balance========== \n\n";
	cout << " Id:  "   <<    id << endl;
	cout << " Bal. " << balance << endl;
}

void BankAccount :: task(int choice)
{		
	if 		( choice == 1 ) { display();  }
	else if ( choice == 2 ) { deposit();  }
	else if ( choice == 3 ) { withdraw(); }

	else    { cout << "Invalid Choice"; }

}

void BankAccount :: deposit()
{
	int deposit_amt;
	cout << endl << " =========Deposit=========== \n\n";
	cout << "Enter amount to deposit: ";
	cin >> deposit_amt;

	this->balance += deposit_amt;
	this->display();
}

void BankAccount :: withdraw()
{
	int withdraw_amt = 0;
	cout << endl << " =========Withdraw=========== \n\n";

	while(!withdraw_amt) {

		cout << "Enter amount to withdraw: ";
		cin >> withdraw_amt;

		if(withdraw_amt <= this->balance) {
			this->balance -= withdraw_amt;
		}
		else {
			withdraw_amt = 0;
			cout << endl << " *** Amount you entered is more than current balance*** ";
		}
		this->display();
	}

}


int BankAccount :: count = 1;

int main()
{
	BankAccount ba[10];

	for (int i = 0; i < 10; ++i) {
		ba[i].display();	
	}

	int bank_task = 0;
	while(!bank_task) {

		int accountId = askAccountId();

		int choice    = ba[accountId - 1].askChoice();

		ba[accountId - 1].task(choice);
		cout << endl << "Enter 0 to continue: ";
		cin >> bank_task;

	}

	return 0;
}