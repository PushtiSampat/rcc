#include<iostream>
using namespace std;
int main ()
{

    // 1d array
    int a[] = {10, 20, 30, 40, 50};
    int *ptr1;
    
    ptr1 = a;
    //or
    ptr1 = &a[0];

    // Here if you write a, a has address of array. &a will give an error

    for (int i = 0; i < 5; i ++) {
        cout << ":" << ptr1[i] << endl;
    }

    cout << "\n===================\n";

    for (int i = 0; i < 5; i ++) {
        cout << ptr1 << endl;
        cout << *ptr1++ << endl;
    }
    

    cout << "\n===================\n";
    cout << endl;
    int (*ptr2)[5];
    ptr2 = &a;

    // "(*ptr2)[5]" & "*ptr2[5]" are two different things
    //if  i chnage array a to more or less elements than 5, it will create an error

    cout << ptr2 << endl << endl;

    cout << (ptr2)[0] << endl;
    cout << (*ptr2)[0] << endl << endl;

    cout << &(*ptr2)[1] << endl;
    cout << (*ptr2)[1] << endl;



    cout << "\n===================\n";
    cout << endl;

    int *(ptr3[5]);
    ptr3[0] = a;
    //or
    ptr3[0] = &a[0];

    cout << (ptr3[0] + 1) << endl;
    cout << *(ptr3[0] + 1) << endl;

    cout << (ptr3[0] + 1)[0] << endl;




    cout << "\n===================\n";
    cout << endl;

    int *(ptr4)[5];
    ptr4[0] = &a[0];
    //or
    ptr4[0] = a;

    cout << (ptr4[0] + 1) << endl;
    cout << *(ptr4[0] + 1) << endl;


    cout << "\n===================\n";
    cout << endl;

    int *ptr5[5];
    ptr5[0] = &a[0];
    //or
    ptr5[0] = a;
    
    cout << (ptr5[0] + 1) << endl;
    cout << *(ptr5[0] + 1) << endl;

    return 0;
}
