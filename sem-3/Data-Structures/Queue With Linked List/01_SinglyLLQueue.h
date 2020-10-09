#include<iostream>
#include<new>  // For: new(nothrow)

using namespace std;

template <typename T> 

class QueueClass{
    class QueueNode{  // Creating QueueNode
        public:
            T data;
            QueueNode* next;
    };

    int currentQueueLength = 0;
    QueueNode *topHead;  // Head of the Queue

    public:
        QueueClass()  // Default Constructor
        {
            topHead = NULL;
        }
        ~QueueClass(){}

        QueueNode *newQueueNode()  // Creating New Node
        {
            QueueNode *new_node = new QueueNode;
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
            QueueNode *new_node = newQueueNode();

            new_node -> data = data;
            
            if (topHead == NULL){  // Push to Empty Queue
                topHead = new_node;
                new_node -> next = NULL;
            }
            else{  // Push to Non Empty Queue
                QueueNode *curr = topHead;
                while(curr){
                    if(curr -> next == NULL){
                        break;
                    }
                    curr = curr -> next;
                }
                curr -> next = new_node;
                new_node -> next = NULL;
            }

            currentQueueLength += 1;  // Queue Length Increment

            /* display(); */            
            return new_node -> data;
        }

        T pop()
        {
            if (topHead == NULL) {
                return '\0'; // Blank Space Ascii
            }

            // Next Node Becomes Top
            QueueNode *topNode = topHead;  
            topHead = topHead -> next;

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
            QueueNode *curr = topHead;

            while(curr) {
                cout << curr -> data;
                curr = curr -> next;
                if (curr) {
                    cout << ", ";
                }
            }
            cout << "]\n\n";
        }
};
