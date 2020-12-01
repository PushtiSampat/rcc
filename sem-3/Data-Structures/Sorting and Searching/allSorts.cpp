#include"Sort.h"
#include"printArray.h"

#define MAX 10

using namespace std;

int main()
{
    int arr[MAX];
    int n;

    cout << "How many elements do you want to enter: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    cout << endl << "Bubble Sort" << endl;
    int *sortedArray1 = bubbleSort(arr, n);
    printArray(sortedArray1, n);

    cout << endl << "Selection Sort" << endl;
    int *sortedArray2 = selectionSort(arr, n);
    printArray(sortedArray2, n);

    cout << endl << "Insertion Sort" << endl;
    int *sortedArray3 = insertionSort(arr, n);
    printArray(sortedArray3, n);

    cout << endl << "Radix Sort" << endl;
    int *sortedArray4 = RadixSort(arr, n);
    printArray(sortedArray4, n);

    return 0;
}
