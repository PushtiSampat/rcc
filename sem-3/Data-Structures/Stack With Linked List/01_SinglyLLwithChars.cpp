#include"01_SinglyLLforStack.h"
#include<iostream>
#include<new>

using namespace std;

int main()
{
    StackClass<char> *s = new StackClass <char>;

    s->push('A');
    s->display();

    s->pop();
    s->display();

    s->pop();
    s->display();

    s->push('B');
    s->display();

    s->push('C');
    s->display();

    return 0;
}
