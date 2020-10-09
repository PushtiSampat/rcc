#include <iostream>
using namespace std;

class DoublyCircularLL
{
    class Node
    {
    public:
        int data;
        Node *previousNode, *nextNode;

        Node(int value)
        {
            data = value;
            previousNode = nextNode = NULL;
        }
    };
    int size;
    Node *head, *last;

public:
    DoublyCircularLL()
    {
        head = last = NULL;
    }

    void create()
    {
        short op;
        int value;

        do
        {
            cout << "Enter data of the node: ";
            cin >> value;

            Node *node = new Node(value);
            if (!head)
                head = last = node;
            else
            {
                node->previousNode = last;
                last->nextNode = node;
                last = node;
            }

            cout << "Enter 1 to continue, 0 to stop: ";
            cin >> op;

        } while (op);

        last->nextNode = head;
        head->previousNode = last;
    }

    void addToFront(int value)
    {
        Node *node = new Node(value);
        if (!head)
        {
            head = last = node;
        }
        else
        {
            node->nextNode = head;
            node->previousNode = last;
            head->previousNode = node;
            head = node;
            last->nextNode = head;
        }
    }

    void addToLast(int value)
    {
        Node *node = new Node(value);
        if (!head)
        {
            head = last = node;
            head->previousNode = last;
            last->nextNode = head;
        }
        else
        {
            node->previousNode = last;
            node->nextNode = head;
            last->nextNode = node;
            last = node;
            head->previousNode = last;
        }
    }

    bool isEmpty()
    {
        return !head;
    }

    int deleteFromFront()
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return NULL;
        }

        Node *nodeToBeDeleted = head;
        int deletedData = head->data;

        if (head == last)
            head = last = NULL;
        else
        {
            head = head->nextNode;
            head->previousNode = last;
            last->nextNode = head;
        }

        nodeToBeDeleted->nextNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    int deleteNode(int value)
    {
        Node *nodeToBeDeleted = searchNode(value);
        if (!nodeToBeDeleted)
        {
            cout << "Node with given data not found!" << endl;
            return NULL;
        }

        if (head == nodeToBeDeleted)
            return deleteFromFront();

        if (last == nodeToBeDeleted)
            return deleteFromLast();

        int deletedData = nodeToBeDeleted->data;

        Node *itsPreviousNode = nodeToBeDeleted->previousNode;
        Node *itsNextNode = nodeToBeDeleted->nextNode;

        itsPreviousNode->nextNode = itsNextNode;
        itsNextNode->previousNode = itsPreviousNode;

        nodeToBeDeleted->nextNode = NULL;
        nodeToBeDeleted->previousNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    int deleteFromLast()
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return NULL;
        }

        Node *nodeToBeDeleted = last;
        int deletedData = last->data;

        if (head == last)
            head = last = NULL;
        else
        {
            last = last->previousNode;
            last->nextNode = head;
            head->previousNode = last;
        }

        nodeToBeDeleted->previousNode = NULL;
        delete nodeToBeDeleted;
        return deletedData;
    }

    Node *searchNode(int value)
    {
        if (last && last->data == value)
            return last;

        Node *node = head;
        while (node)
        {
            if (node->data == value)
                return node;
            node = node->nextNode;
        }
        return NULL;
    }

    void addBefore(int nextValue, int value)
    {
        Node *itsNextNode = searchNode(nextValue);
        if (!itsNextNode)
            cout << "Node with given data not found!" << endl;
        else
        {
            if (itsNextNode == head)
                return addToFront(value);

            Node *node = new Node(value);
            Node *itsPreviousNode = itsNextNode->previousNode;

            node->nextNode = itsNextNode;
            node->previousNode = itsPreviousNode;

            itsPreviousNode->nextNode = node;
            itsNextNode->previousNode = node;
        }
    }

    void addAfter(int previousValue, int value)
    {
        Node *itsPreviousNode = searchNode(previousValue);
        if (!itsPreviousNode)
            cout << "Node with given data not found!" << endl;
        else
        {
            if (itsPreviousNode == last)
                return addToLast(value);

            Node *node = new Node(value);
            Node *itsNextNode = itsPreviousNode->nextNode;

            node->nextNode = itsNextNode;
            node->previousNode = itsPreviousNode;

            itsPreviousNode->nextNode = node;
            itsNextNode->previousNode = node;
        }
    }

    void display()
    {

        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        cout << "Doubly Linked List" << endl;
        Node *node = head;

        do
        {
            cout << node->data << " <=> ";
            node = node->nextNode;
        } while (node != head);
        cout << "\b\b\b\b     \n";
    }

    void displayReverse()
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Reversed Doubly Linked List" << endl;
        Node *node = last;
        do
        {
            cout << node->data << " <=> ";
            node = node->previousNode;
        } while (node != last);
        cout << "\b\b\b\b     \n";
    }
};

void menu();
int readNumber(string);
void displayDeletedData(int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    DoublyCircularLL dll;

    dll.create();

    short option;
    int value, anotherValue;

    do
    {
        cout << "-> 1. Insert at front" << endl;
        cout << "-> 2. Insert at last" << endl;
        cout << "-> 3. Insert before" << endl;
        cout << "-> 4. Insert after" << endl;
        cout << "-> 5. Delete from front" << endl;
        cout << "-> 6. Delete from last" << endl;
        cout << "-> 7. Delete Node" << endl;
        cout << "-> 8. Display" << endl;
        cout << "-> 9. Display Reverse" << endl;
        cout << "-> 0. Exit" << endl;
        cout << "-> ";
        cin >> option;

        switch (option)
        {
        case 1:
            value = readNumber("Enter a number to insert at front: ");
            dll.addToFront(value);
            break;
        case 2:
            value = readNumber("Enter a number to insert at last: ");
            dll.addToLast(value);
            break;
        case 3:
            anotherValue = readNumber("Enter a number before which you want to insert: ");
            value = readNumber("Enter a number to insert: ");
            dll.addBefore(anotherValue, value);
            break;
        case 4:
            anotherValue = readNumber("Enter a number after which you want to insert: ");
            value = readNumber("Enter a number to insert: ");
            dll.addAfter(anotherValue, value);
            break;
        case 5:
            value = dll.deleteFromFront();
            displayDeletedData(value);
            break;
        case 6:
            value = dll.deleteFromLast();
            displayDeletedData(value);
            break;
        case 7:
            value = readNumber("Enter the value to delete: ");
            anotherValue = dll.deleteNode(value);
            displayDeletedData(anotherValue);
            break;
        case 8:
            dll.display();
            break;
        case 9:
            dll.displayReverse();
            break;
        case 0:
            break;
        default:
            cout << "Wrong Choice" << endl;
        }

    } while (option);
}

int readNumber(string message)
{
    int value;
    cout << message;
    cin >> value;
    return value;
}

void displayDeletedData(int deletedData)
{
    if (deletedData)
        cout << "Deleted: " << deletedData << endl;
}