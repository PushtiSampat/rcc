#include<iostream>
#define SIZE 50

using namespace std;

class Heap{
    bool printTree = true;
    int n = 0;
    int heap[SIZE]={0};

    public:
    int getSize()
    {
        return n;
    }
    void deletionHeapify()
    {
        int parent = 0;
        int child;

        while(1){
            int leftChild = (parent*2) + 1; // 5
            int rightChild = (parent*2) + 2; 

            // Left Child does not exists
            if(leftChild >= n){
                return;
            }

            // Left exists but right Child does not
            if(rightChild >= n){
                // If left child is larger
                if(heap[leftChild] < heap[parent]){
                    swap(heap[parent], heap[leftChild]);
                }
                return;
            }

            // Both Child exists

            // Making the lower value as child
            if(heap[leftChild] < heap[rightChild])
                child = leftChild;
            else
                child = rightChild;

            if(heap[parent] > heap[child]){
                swap(heap[parent], heap[child]);
            }
            parent = child;
        }

    }
    void deleteElement()
    {
        int root = 0;
        int deletedElement = heap[root];
        heap[root] = heap[n - 1];
        n--;
        deletionHeapify();

        cout << "\n\t-" << deletedElement;
        if(printTree){
            printHeap();
        }
    }

    void insertionHeapify()
    {
        int child = n - 1;
        while(child > 0){
            int parent = (child - 1) / 2;

            if(heap[parent] < heap[child]) return;

            swap(heap[parent], heap[child]);
            child = parent;
        }
    }

    void insert(int data)
    {
        n++;
        heap[n - 1] = data;
        insertionHeapify();
        if(printTree){
            cout << "\n\t+" << data;
            printHeap();
        }
    }

    void printHeap()
    {
        int j = 0;
        if(!n){
            cout << "\nEmpty Heap";
            return;
        }
        
        cout << "\n------------------\n";
        for(int i = 0; i < n; i++){
            cout << heap[i] << " ";

            if(i == j){
                j = (j * 2) + 2;
                cout << endl;
            }

        }
        cout << "\n------------------\n";
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
    heap -> insert(25);
    heap -> insert(35);
    heap -> insert(12);
    heap -> insert(122);
    heap -> insert(128);
    heap -> insert(67);
    heap -> insert(172);
    heap -> insert(22);

    int size = heap -> getSize();
    for(int i = 0; i < size; i++) {
        heap -> deleteElement();
    }

    cout << "\n\n *********** Printing Final Heap **********" << "\n";
    heap -> printHeap();
    cout << "\n\n";
    return 0;
}
