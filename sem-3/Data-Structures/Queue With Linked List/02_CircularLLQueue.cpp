#include<iostream>
#include"02_CircularLLQueue.h"
#include<stdlib.h>
#include<string>

using namespace std;

int main()
{

    CircularQueue<int> *my_queue =  new(nothrow) CircularQueue<int>;

    // ---------------------------------------
    cout << "+ " << my_queue -> push(10)<< endl;
    my_queue -> display();

    cout << "- " << my_queue -> pop() << endl;
    my_queue -> display();

    cout << "- " << my_queue -> pop() << endl;
    my_queue -> display();

    cout << "+ " << my_queue -> push(15)<< endl;
    my_queue -> display();

    cout << "- " << my_queue -> pop() << endl;
    my_queue -> display();
    
    cout << "+ " << my_queue -> push(20)<< endl;
    my_queue -> display();

    cout << "+ " << my_queue -> push(30)<< endl;
    my_queue -> display();

    cout << "+ " << my_queue -> push(40)<< endl;
    my_queue -> display();

    cout << "+ " << my_queue -> push(50)<< endl;
    my_queue -> display();
    
    // ---------------------------------------
    cout << "- " << my_queue -> pop() << endl;
    my_queue -> display();

    /* ----------------------------------------------------- */

    return 0;
}
