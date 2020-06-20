#include<iostream>
#include<string>

using namespace std;

class Student
{
	private :
	static int count;
	int roll;
	char name[50];
	int age;
	int marks[3];

	public :
	Student();
	void getData();
	void display();
	void editDetails();

};

Student :: Student()
{
	int subjects = 3;
	roll = ++count;
	for (int i = 0; i < subjects; ++i) {
		marks[i] = 35;
	}
}

void Student :: getData()
{
	cout << "Enter name of Roll No. " << this->roll << ": "; 
	cin >> this->name;

	cout << "Enter age of Roll No. " << this->roll << ": "; 
	cin >> this->age;

	cout << endl;
}

void Student :: display()
{
	int subjects = 3;
	
	cout << endl << " Roll no: " << roll;
	cout << endl << " Name:    " << name;
	cout << endl << " Age:     " << age;

	for (int i = 0; i < subjects; ++i) {
		cout << endl << " Subject" << i << ": " << marks[i]; 
	} 

	cout << "\n\n";
}

void Student :: editDetails()
{
	int marks;
	for (int i = 0; i < 3; ++i) {
		cout << "Enter marks of Subject " << i << endl;
		cin >> marks;
		this->marks[i] = marks;
	}
}

int askRoll()
{
	int roll;
	cout << endl << "Enter roll no whose details you want to edit " << endl;
	cin >> roll;
	return roll;
}

int Student :: count;

int main()
{	
	int stud_count = 3;
	Student stud[3];
	for (int i = 0; i < stud_count; ++i) {
		stud[i].getData();
		stud[i].display();
	}

	int editNo = 1;

	while (editNo) {
		editNo = askRoll() - 1;
		stud[editNo].editDetails();
		cout << endl << "Press any  key to continue or 0 to exit : ";
		cin >> editNo;
	}

	for (int i = 0; i < stud_count; ++i) {
		stud[i].display();
	}

	return 0;

}