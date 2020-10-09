#ifndef printArray_H

#include <iostream>


void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        std :: cout << arr[i] << " ";
    }
    std :: cout << std :: endl;
}

#endif
