#include<iostream>
#include<new>  // For: new(nothrow)

using namespace std;

template <typename T> 

class CircularQueue{
    class Node{  // Creating Node
        public:
            T data;
            Node* next;
    };

    int currentQueueLength = 0;
    Node *topHead;  // Head of the Queue

    public:
    CircularQueue()  // Default Constructor
    {
        topHead = NULL;
    }
    ~CircularQueue(){}

    Node *newNode()  // Creating New Node
    {
        Node *new_node = new Node;
        return new_node;
    }

    // Pushing Elements in Queue
    T push(T data, int queueCapacity=0)
    {
        // If Queue Capacity is 0, the Queue Capacity has no limit
        if (currentQueueLength  >= queueCapacity && queueCapacity){
            cout << "-Queue Overflow\n";
            return 0;
        }

        // Creating New Node
        Node *new_node = newNode();

        new_node -> data = data;

        if (topHead == NULL){  // Push to Empty Queue
            topHead = new_node;
            new_node -> next = new_node;
        }
        else{  // Push to Non Empty Queue
            Node *curr = topHead;

            while(curr -> next != topHead)
                curr = curr -> next;

            curr -> next = new_node;
            new_node -> next = topHead;
        }

        currentQueueLength += 1;  // Queue Length Increment

        /* display(); */            
        return new_node -> data;
    }

    T pop()
    {
        if (topHead == NULL) {
            return '\0';
        }

        // Next Node Becomes Top
        Node *topNode = topHead;  

        // If only 1 Element is there is in Queue
        if(topHead == topHead -> next){
            topHead = NULL;
        }
        // If more than 1 Element is there is in Queue
        else{
            Node *curr = topHead;
            while(curr->next != topHead){
                curr = curr -> next;
            }
            topHead = topHead -> next;
            curr -> next = topHead;
        }

        char popped = topNode -> data;

        // Freeing the popped memory
        free(topNode);

        currentQueueLength -= 1;  // Queue Length Decrement

        /* display(); */
        return popped;

    }

    void display()
    {
        cout << "[";
        Node *curr = topHead;

        if(topHead == NULL){
        }

        else{
            do{
                cout << curr -> data;
                curr = curr -> next;
                if (curr != topHead)
                    cout << ", ";
            } while(curr != topHead);
        }
        cout << "]\n\n";
    }

};
