#include <iostream>
#include <new> //nothrow
#include <string>

using namespace std;

class Employee;

class EmpCollection
{
    public :
        void getData(Employee &);
        void putData(Employee &);
};

class Employee
{
    public:
        int   id;
        char  emp_name[20];

    public :
        int getRoll();
        friend void EmpCollection :: getData(Employee &);
        friend void EmpCollection :: putData(Employee &);


};

void EmpCollection :: getData (Employee &c) 
{
    cout << endl << "===========";
    cout << endl << "Enter id no: ";
    cin >> c.id;

    cout << endl << "Enter emp_name: ";
    cin >> c.emp_name;

}


void EmpCollection :: putData (Employee &c) 
{

    cout << endl << "========" << endl;

    cout << "Make: " << c.id << endl;
    cout << "Color: " << c.emp_name << endl;
}

//Driver Code
int main ()
{
    int n = 0;

    cout << "Enter number of employee: ";
    cin >> n;

    Employee *employee = new(nothrow) Employee[50];
    EmpCollection *empCollection = new(nothrow) EmpCollection[50];

    
    for (int i = 0; i < n; i++) {
        empCollection[i].getData(employee[i]);
    }

    for (int i = 0; i < n; i++) {
        empCollection[i].putData(employee[i]);
    }

    return 0;

}


