/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      singleLinkedListStack.cpp
 * Copyright: 20-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a menu driven program to perform 
 *           Stack Operations on singly Linked List
 * 
 * ========================================================== */


#include<bits/stdc++.h>
#include<new>  // For `new(nothrow)`

using namespace std;

class StackClass{
    class StackNode{  // Creating StackNode
        public:
            int data;
            StackNode* next;
    };

    int currentStackLength = 0;
    StackNode *topHead;  // Head of the Stack

    public:
        StackClass()  // Default Constructor
        {
            topHead = NULL;
        }

        StackNode *newStackNode()  // Creating New Node
        {
            StackNode *new_node = new StackNode;
            return new_node;
        }

        // Pushing Elements in Stack
        int push(int data, int stackCapacity=0)
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

            display();            
            return new_node -> data;
        }

        int pop()
        {
            if (topHead == NULL){  // If Stack is Empty
                cout << "-Cannot pop an Empty Stack\n";
                return 0;
            }

            // Next Node Becomes Top
            StackNode *topNode = topHead;  
            topHead = topHead -> next;

            int popped = topNode -> data;

            // Freeing the popped memory
            free(topNode);
            
            currentStackLength -= 1;  // Stack Length Decrement

            display();
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

int main()
{
    StackClass *my_stack = new(nothrow) StackClass;
    bool True = 1;
    int ret, num, stackCapacity;
    char stackLimitChoice;

    // Asking if Stack has Limit of Capacity
    cout << "Does Stack has a Limit? y/n: ";
    cin >> stackLimitChoice;

    // If Capacity is Limited
    if (stackLimitChoice == 'y') {
        cout << "What is capacity of Stack: ";
        cin >> stackCapacity;

        if (stackCapacity == 0) {
            exit(0);
        }
    }

    // Incorrect Input
    else if(stackLimitChoice != 'n') {
        cout << "Invalid Choice\n";
        exit(1);
    }

    cout << "\nEnter 0 to exit\n";
    cout << "Enter -1 to pop\n\n";

    while (True){
        cout << "Enter a number: ";  // Taking Input
        cin >> num;

        // Exit
        if(num == 0) break;

        // Pop
        else if (num == -1) ret = my_stack -> pop();

        // Push
        else {
            if (stackLimitChoice == 'n')  // Stack Capacity has no Limit
                ret = my_stack -> push(num);  
            else  // Stack Capacity is Limited
                ret = my_stack -> push(num, stackCapacity);
        }
        
    }

    // Displaying Stack
    my_stack -> display();

    return 0;
}

/* ===========================================================
Output:

    Does Stack has a Limit? y/n: y
    What is capacity of Stack: 3

    Enter 0 to exit
    Enter -1 to pop

    Enter a number: -1
    -Cannot pop an Empty Stack
    Enter a number: 10
    [10]
    Enter a number: 20
    [20, 10]
    Enter a number: 40
    [40, 20, 10]
    Enter a number: -1
    [20, 10]
    Enter a number: 30
    [30, 20, 10]
    Enter a number: 40
    -Stack Overflow
    Enter a number: 0
    [30, 20, 10]

============================================================= */

