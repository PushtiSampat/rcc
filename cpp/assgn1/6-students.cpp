#include <iostream>
#include <new> //nothrow
#include <string>

using namespace std;

class Students
{
    public:
        int   roll;
        char  name[20];
        int   marks[3];
        int   max_marks;
        float per;

    public :
        int getRoll();
        void getData(void);
        void putData(void);

    Students ()
    {
        this -> max_marks = 0;
    }
};

class Mca2 : public Students // public derivation
{
    public :
        void add(int n);
        void remove(int);
        void modify(int);
        void replace(int, int);
};

void Students :: getData (void) 
{
    int total = 0;
    cout << endl << "Enter roll no: ";
    cin >> this -> roll;

    cout << endl << "Enter name: ";
    cin >> this -> name;

    for (int i = 0; i < 3 ; i++) {
        cout << endl << "Enter marks of Sub " << i + 1 << ": " ;
        cin >> this -> marks[i];

        total += this -> marks[i];

        if (this -> marks[i] > this -> max_marks) {
            this -> max_marks = this -> marks[i];
        }
    }

    this -> per = total / 3;

}

void Students :: putData (void) 
{
    if (!this -> roll) {
        return;    
    }

    cout << endl << "========" << endl;

    cout << "Roll: " << this -> roll << endl;
    cout << "Name: " << this -> name << endl;

    cout << "Marks : ";
    for (int i = 0; i < 3 ; i++) {
        cout << this -> marks[i] << "  ";
    }

    cout << endl;

    cout << "Max Marks: " << max_marks << endl;
    cout << "Per: " << per << endl;

}


void Mca2 :: remove(int roll)
{
    if (this -> roll == roll) {
        this -> roll = 0;
    }
}


void Mca2 :: modify(int roll)
{

    if (this -> roll != roll) {
        return;
    }

    int total = 0;

    cout << endl <<"Modifying record for roll:" << this -> roll; 

    cout << endl << "Enter roll no: ";
    cin >> this -> roll;

    cout << endl << "Enter name: ";
    cin >> this -> name;

    for (int i = 0; i < 3 ; i++) {
        cout << endl << "Enter marks of Sub " << i + 1 << ": " ;
        cin >> this -> marks[i];

        total += this -> marks[i];

        if (this -> marks[i] > this -> max_marks) {
            this -> max_marks = this -> marks[i];
        }
    }

    this -> per = total / 3;

}


void Mca2 :: replace(int roll1, int roll2)
{
    if (this -> roll == roll1) {
        this -> roll = roll2;
    }
    else if (this -> roll == roll2) {
        this -> roll = roll1;
    }
}

//Driver Code
int main ()
{
    int n = 0, choice = 1;

    cout << "Enter number of students in Mca2: ";
    cin >> n;

    Mca2 *mca2 = new(nothrow) Mca2[50];

    if (!mca2) {
        perror ("Error: ");
    }
    
    for (int i = 0; i < n; i++) {
        mca2[i].getData();
    }

    for (int i = 0; i < n; i++) {
        mca2[i].putData();
    }

    while (choice) {
       cout << endl << "Enter your choice: " << endl;
       cout << "1. Add" << endl << "2. Remove" << endl << "3. Modify" << endl << "4. Replace" << endl << "0. Exit"<< endl;
       cin >> choice;

        if (choice == 1) {
            int add_n = 0;

            while (add_n < 1) {
                cout << endl << "How many students you want to add: ";
                cin >> add_n;

                if (add_n < 1) {
                    cout << endl <<  "Enter a positive number : ";
                }
            }

            n += add_n;
            
            for (int i = n - add_n; i < n; i++) {
                mca2[i].getData();
            }

        }

       else if(choice == 2) {
            int roll;
            
            cout << "Enter roll no you want to remove: ";
            cin >> roll;
            
            for (int i = 0; i < n; i++) {
                mca2[i].remove(roll);
            }
       }


       else if(choice == 3) {
            int roll;
            
            cout << "Enter roll no you want to modify: ";
            cin >> roll;
            
            for (int i = 0; i < n; i++) {
                mca2[i].modify(roll);
            }
       }


       else if(choice == 4) {
            int roll1, roll2;
            
            cout << "Enter roll no you want to modify: ";
            cin >> roll1 >> roll2;
            
            for (int i = 0; i < n; i++) {
                mca2[i].replace(roll1, roll2);
            }
       }


        else if(choice == 5) {
            for (int i = 0; i < n; i++) {
                mca2[i].putData();
            }
        }

    }

    for (int i = 0; i < n; i++) {
        mca2[i].putData();
    }

    return 0;

}
