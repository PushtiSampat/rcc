#include<iostream>

int main ()
{
    // 1d array
    int arr[] = {10, 20, 30, 40, 50};
    int (*arrPtr)[5];

    arrPtr = &arr;

    std :: cout << *(arrPtr[0]) << std :: endl;

    std :: cout << *(arrPtr[0] + 1) << std :: endl;

    std :: cout << *(arrPtr[0] + 2) << std :: endl;

    std :: cout << std :: endl;


    // 2d array
    int arr2[][5] = {
        {10, 20, 30},
        {60, 70, 80, 90, 100},
        {1, 2, 3, 4, 5}
    };

    int (*arrPtr2)[5];

    arrPtr2 = &arr2[0];

    std :: cout << *(arrPtr2[2] + 2) << std :: endl;

    std :: cout << *(arrPtr2[1] + 8) << std :: endl;

    std :: cout << *(arrPtr2[0] + 4) << std :: endl;
 


    // 3d array

    //int arr3[][][]


    return 0;
}


