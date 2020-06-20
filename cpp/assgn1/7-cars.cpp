#include <iostream>
#include <new> //nothrow
#include <string>

using namespace std;

class Car
{
    public:
        int   make;
        char  color[20];
        int   size;
        float cost;

    public :
        int getRoll();
        void getData(void);
        void putData(void);


    friend class CarCollection;
};

class CarCollection
{
    public :
        void add(int n);
        void remove(Car &, int);
        void modify(Car &, int);
        void replace(Car &,int, int);
};

void Car :: getData (void) 
{
    cout << endl << "===========";
    cout << endl << "Enter make no: ";
    cin >> this -> make;

    cout << endl << "Enter color: ";
    cin >> this -> color;

    cout << endl << "Enter size: ";
    cin >> this -> size;

    cout << endl << "Enter cost: ";
    cin >> this -> cost;

}

void Car :: putData (void) 
{
    if (!this -> make) {
        return;    
    }

    cout << endl << "========" << endl;

    cout << "Make: " << this -> make << endl;
    cout << "Color: " << this -> color << endl;
    cout << "Size: " << this -> size << endl;
    cout << "Cost: " << this -> cost << endl;
}


void CarCollection :: remove(Car& s, int make)
{
    if (s.make == make) {
        s.make = 0;
    }
}


void CarCollection :: modify(Car& s,int make)
{

    if (s.make != make) {
        return;
    }


    cout << endl <<"Modifying record for make:" << s.make; 

    cout << endl << "Enter make no: ";
    cin >> s.make;

    cout << endl << "Enter color: ";
    cin >> s.color;

    cout << endl << "Enter size: ";
    cin >> s.size;

    cout << endl << "Enter cost: ";
    cin >> s.cost;
}



void CarCollection :: replace(Car& s,int make1, int make2)
{
    if (s.make == make1) {
        s.make = make2;
    }
    else if (s.make == make2) {
        s.make = make1;
    }
}

//Driver Code
int main ()
{
    int n = 0, choice = 1;

    cout << "Enter number of car: ";
    cin >> n;

    CarCollection *mca2 = new(nothrow) CarCollection[50];
    Car *car = new(nothrow) Car[50];

    if (!mca2) {
        perror ("Error: ");
    }
    
    for (int i = 0; i < n; i++) {
        car[i].getData();
    }

    for (int i = 0; i < n; i++) {
        car[i].putData();
    }

    while (choice) {
       cout << endl << "Enter your choice: " << endl;
       cout << "1. Add" << endl << "2. Remove" << endl << "3. Modify" << endl << "4. Replace" << endl << "0. Exit"<< endl;
       cin >> choice;

        if (choice == 1) {
            int add_n = 0;

            while (add_n < 1) {
                cout << endl << "How many car you want to add: ";
                cin >> add_n;

                if (add_n < 1) {
                    cout << endl <<  "Enter a positive number : ";
                }
            }

            n += add_n;
            
            for (int i = n - add_n; i < n; i++) {
                car[i].getData();
            }

        }

       else if(choice == 2) {
            int make;
            
            cout << "Enter make no you want to remove: ";
            cin >> make;
            
            for (int i = 0; i < n; i++) {
                mca2[i].remove(car[i], make);
            }
       }


       else if(choice == 3) {
            int make;
            
            cout << "Enter make no you want to modify: ";
            cin >> make;
            
            for (int i = 0; i < n; i++) {
                mca2[i].modify(car[i],make);
            }
       }


       else if(choice == 4) {
            int make1, make2;
            
            cout << "Enter make no you want to modify: ";
            cin >> make1 >> make2;
            
            for (int i = 0; i < n; i++) {
                mca2[i].replace(car[i], make1, make2);
            }
       }


        else if(choice == 5) {
            for (int i = 0; i < n; i++) {
                car[i].putData();
            }
        }

    }

    for (int i = 0; i < n; i++) {
        car[i].putData();
    }

    return 0;

}

