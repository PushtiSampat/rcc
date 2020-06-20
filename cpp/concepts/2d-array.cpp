#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    const int rows = 3;
    const int cols = 5;

    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {60, 70, 80, 90, 100};
    int arr3[] = {110, 120, 130, 140, 150};

    int **p1;
    int *(p2[cols]); 

    p2[0] = arr1;
    p2[1] = arr2;
    p2[2] = arr3;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++ ) {
            cout << setw(3) << &((p2[i]) [j]) <<  "  "; 
            cout << setw(3) <<  (p2[i]) [j] <<  " | "; 
        }
        cout << endl;
    }
    
    cout << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) <<  (p2[i] + j) << "  ";
            cout << setw(3) << *(p2[i] + j) << " | ";
        }
        cout << endl;
    }

    p1 = p2;

    cout << endl;
    cout << *p1 << endl;
    cout << p1[0] << endl;

    cout << endl;
    cout << *(*p1) << endl;
    cout << p1[0][0] << endl;
     


    return 0;
}