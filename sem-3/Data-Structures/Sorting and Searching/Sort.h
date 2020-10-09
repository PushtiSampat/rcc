#ifndef Sort_H
#define Sort_H

#include"swap.h"


// Bubble Sort
int* bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    return arr;
}


// Selection Sort
int* selectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;

        swap(&arr[min], &arr[i]);
    }
    return arr;
}

// Insertion Sort
int* insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}
#endif
