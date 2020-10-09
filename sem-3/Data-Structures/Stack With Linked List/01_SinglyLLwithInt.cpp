#include"01_SinglyLLforStack.h"
#include<iostream>
#include<new>

using namespace std;

int main()
{
    StackClass<int> *s = new StackClass <int>;

    s->push(10);
    s->display();

    s->pop();
    s->display();

    s->pop();
    s->display();

    s->push(20);
    s->display();

    s->push(30);
    s->display();

    return 0;
}
