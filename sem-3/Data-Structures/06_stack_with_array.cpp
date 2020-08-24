/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      stack_with_array.cpp
 * Copyright: 25-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to push, pop, display elements in
 *           stack using Array
 * 
 * ========================================================== */
 
#include <iostream>
using namespace std;

int stack[100], n = 5, top = -1;

// Display Stack
void display() {
    cout << "[";

    for(int i=top; i>=1; i--)
        cout << stack[i] << ", ";

    if (top >= 0)
        cout << stack[0];
    cout << "]\n\n" ;
}


// Push into stack
int push(int val) {

    // Stack Overflow
    if(top>=n-1)
        cout << "Stack Overflow" << endl;
    else {
        top += 1;
        stack[top]=val;
    }

    display();
    return stack[top];
}


// Pop from Stack
int pop() {
    int popped = stack[top];

    // If Stack is already Empty
    if(top<=-1)
        cout << "Cannot remove from Empty Stack" << endl;

    // If Stack is NOT Empty
    else
        cout << "The popped element is "<< stack[top--] << endl;

    display();

    return popped;
    
}


// Driver Code
int main() {
    int ch, val;
    cout << "1) Push \n2) Pop \n3) Display \n4) Exit\n";
    do {
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch) {
            // Push into Stack
            case 1: {
                        cout << "Enter data: ";
                        cin >> val;
                        push(val);
                        break;
                    }

            // Pop from stack
            case 2: { pop(); break; }

            // Display stack
            case 3: { display(); break; }

            // Exit
            case 4: { cout << "Exit" << endl; break; }

            // Invalid Choice
            default: { cout << "Invalid Choice" << endl; }
        }
    }while(ch!=4);
    return 0;
}


/* ===========================================================
Output:

    1) Push
    2) Pop
    3) Display
    4) Exit
    Enter choice: 1
    Enter data: 10
    [10]

    Enter choice: 2
    The popped element is 10
    []

    Enter choice: 2
    Cannot remove from Empty Stack
    []

    Enter choice: 1
    Enter data: 10
    [10]

    Enter choice: 1
    Enter data: 20
    [20, 10]

    Enter choice: 1
    Enter data: 30
    [30, 20, 10]

    Enter choice: 1
    Enter data: 40
    [40, 30, 20, 10]

    Enter choice: 1
    Enter data: 50
    [50, 40, 30, 20, 10]

    Enter choice: 1
    Enter data: 60
    Stack Overflow
    [50, 40, 30, 20, 10]

    Enter choice: 4
    Exit

 * ========================================================== */
