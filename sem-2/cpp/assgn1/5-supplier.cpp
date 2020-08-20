

// =========================================================
// Q5: Supplier Starts

#include<iostream>
#include<string>
#include <new> // nothrow


using namespace std;

//class Suppliers
class Suppliers
{
    private :
        char supplier_name[50];
        int no_of_items;
        
    public:
        int getData(void);
        int putData(void);
};


// class items
class Items
{
    private :
        char items[5][50];
    public :
        void getData(int);
        void putData(int);
};


// Functions of Suppliers Class
int Suppliers :: getData(void)
{
    this -> no_of_items = 0;

    cout << endl << "Enter Name of Supplier: ";
    cin >> this -> supplier_name;

    while (this -> no_of_items < 1) {
        cout << endl << "Enter no of items supplied by " << this -> supplier_name << ": ";
        cin >> this -> no_of_items;

        if (this -> no_of_items < 1 || this -> no_of_items > 5)
            cout << endl << "Enter number of items between 1-5";
    }

    return this -> no_of_items;
}

int Suppliers :: putData(void)
{
    cout << endl << "============"  << endl;
    cout << this -> supplier_name;

    return this -> no_of_items;
}


//Functions of item class

void Items :: getData(int no_of_items)
{
    for (int i = 0; i < no_of_items; i++) {
        cout << "Enter Item name: " << i + 1 <<": ";
        cin >> this -> items[i];
    }
}

void Items :: putData(int no_of_items)
{
    for (int i = 0; i < no_of_items; i++) {
        cout << endl << "\t" << this -> items[i];
    }
}


// Driver Code
int main ()
{
    int number_of_suppliers;
    int no_of_items;
    cout << "How many suppliers are there ";
    cin >> number_of_suppliers;

    Suppliers *suppliers = new(nothrow) Suppliers[number_of_suppliers];
    Items *items = new(nothrow) Items[number_of_suppliers];

    if(!suppliers || !items) {
        perror ("Error");
    }

    for (int i = 0; i < number_of_suppliers; i++) {
        no_of_items = suppliers[i].getData();
        items[i].getData(no_of_items);
    }

    for (int i = 0; i < number_of_suppliers; i++) {
        no_of_items = suppliers[i].putData();
        items[i].putData(no_of_items);
    }
    
    cout << endl;
    return 0;
}



// Q5: Supplier Ends
// =========================================================

