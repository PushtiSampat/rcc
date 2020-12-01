#include <iostream> 
using namespace std; 

int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

void radixsort()
{
    
}

// Driver Code 
int main() 
{ 
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	radixsort(arr, n); 
	return 0; 
}

