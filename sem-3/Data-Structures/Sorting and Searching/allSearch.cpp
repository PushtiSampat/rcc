#include"Search.h"
#include<iostream>
#define SIZE 5

using namespace std;

int main()
{
    int a[SIZE] = {10, 20, 30, 30, 50};

    cout << endl << "Linear Search" << endl;
    cout << "Found at index: "<< linearSearch(10, a, SIZE) << endl;
    cout << "Found at index: "<< linearSearch(20, a, SIZE) << endl;
    cout << "Found at index: "<< linearSearch(30, a, SIZE) << endl;
    cout << "Found at index: "<< linearSearch(40, a, SIZE) << endl;
    cout << "Found at index: "<< linearSearch(50, a, SIZE) << endl;

    cout << endl << "Binary Search" << endl;
    cout << "Found at index: "<< binarySearch(10, a, SIZE) << endl;
    cout << "Found at index: "<< binarySearch(20, a, SIZE) << endl;
    cout << "Found at index: "<< binarySearch(30, a, SIZE) << endl;
    cout << "Found at index: "<< binarySearch(40, a, SIZE) << endl;
    cout << "Found at index: "<< binarySearch(50, a, SIZE) << endl;
}
