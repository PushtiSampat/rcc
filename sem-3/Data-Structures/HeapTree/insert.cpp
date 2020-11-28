#include<iostream>
#define SIZE 50

using namespace std;

class Heap{
    int n = 0;
    int heap[SIZE]={0};

    public:
    void maxHeapInsertion()
    {
        int child = n - 1;
        while(child > 0){
            int parent = (child - 1) / 2;

            if(heap[parent] > heap[child]) return;

            swap(heap[parent], heap[child]);
            child = parent;
        }
    }

    void insert(int data)
    {
        n++;
        heap[n - 1] = data;
        maxHeapInsertion();
    }

    void printHeap()
    {
        int j = 0;

        for(int i = 0; i < n; i++){
            cout << heap[i] << " ";

            if(i == j){
                j = (j * 2) + 2;
                cout << endl;
            }

        }
    }
};

int main()
{
    Heap *heap = new Heap();

    heap -> insert(10);
    heap -> insert(5);
    heap -> insert(3);
    heap -> insert(2);
    heap -> insert(4);
    heap -> insert(15);

    heap -> printHeap();
    return 0;
}

/*
Input:
10 5 3 2 4 15 

Output:
15 5 10 2 4 3 
*/
