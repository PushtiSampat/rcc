#include<bits/stdc++.h>
#include<new>  // For `new(nothrow)`

using namespace std;

// Creating StackNode
class StackNode{
    /* private: */
    public:
        int data;
        StackNode* next;
    public:
        void StackOperations();
        StackNode *newStackNode(int data);
        StackNode push(int data);
        void pop();
        void display(StackNode *root);
}



StackNode *StackNode :: newStackNode(int data)
{
    StackNode *stackNode = new(nothrow) StackNode;
    StackNode -> data = data;
    StackNode -> next = NULL;

    return StackNode;
}

StackNode* newNode(int data) 
{ 
    StackNode* stackNode = new StackNode(); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 

void stackOperations(StackNode **)
{
    int choice;

    cout << "1. Push \n" "2. Pop \n" "3.Display\n" "4. Exit\n" ">>> ";
    cin >> choice;
    
    if (choice == 1){
        int data;

        cout << "Enter data to push: ";
        cin >> data;

        /* stackNode = push(data); */
    }
    else if (choice == 2){
        // Pop
    }
    else if(choice == 3) {
        // Display
    }
    else if(choice == 4) {
        exit(0);
    }
    else{
        cout << "Invalid Choice\n";
    }
}

int main()
{
    StackClass *my_stack = new(nothrow) StackClass;

    StackNode *head = NULL;
    
    stackOperations(&head);

    return 0;
}
