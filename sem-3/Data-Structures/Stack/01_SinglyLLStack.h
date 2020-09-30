#ifndef SinglyLinkedListStack_H
#define SinglyLinkedListStack_H

#include<iostream>
#include<new>  // For: new(nothrow)

using namespace std;

template <typename T> 

class StackClass{
    class StackNode{  // Creating StackNode
        public:
            T data;
            StackNode* next;
    };

    int currentStackLength = 0;
    StackNode *topHead;  // Head of the Stack

    public:
        StackClass()  // Default Constructor
        {
            topHead = NULL;
        }
        ~StackClass(){}

        StackNode *newStackNode()  // Creating New Node
        {
            StackNode *new_node = new StackNode;
            return new_node;
        }

        // Pushing Elements in Stack
        T push(T data, int stackCapacity=0)
        {
            // If Stack Capacity is 0, the Stack Capacity has no limit
            if (currentStackLength  >= stackCapacity && stackCapacity){
                cout << "-Stack Overflow\n";
                return 0;
            }

            // Creating New Node
            StackNode *new_node = newStackNode();

            new_node -> data = data;
            
            if (topHead == NULL){  // Push to Empty Stack
                topHead = new_node;
                new_node -> next = NULL;
            }
            else{  // Push to Non Empty Stack
                new_node -> next = topHead;
                topHead = new_node;
            }

            currentStackLength += 1;  // Stack Length Increment

            /* display(); */            
            return new_node -> data;
        }

        T pop()
        {
            if (topHead == NULL) {
                return '\0';  // c[i] = (char) 0;
                /* The null/empty char is simply a value of zero,
                 * but can also be represented as a character with an escaped zero. */
            }

            // Next Node Becomes Top
            StackNode *topNode = topHead;  
            topHead = topHead -> next;

            T popped = topNode -> data;

            // Freeing the popped memory
            free(topNode);
            
            currentStackLength -= 1;  // Stack Length Decrement

            /* display(); */
            return popped;
            
        }

        void display()
        {
            cout << "[";
            StackNode *curr = topHead;

            while(curr) {
                cout << curr -> data;
                curr = curr -> next;
                if (curr) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        }
};

#endif
