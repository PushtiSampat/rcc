#include"tree.h"
#include<iostream>
#include<new>

using namespace std;

int main()
{
    Tree<int> *t = new Tree<int>;
    int data = 1;

    while(data){
        cin >> data;
        if(!data){
            break;
        }
        cout << "+" << t -> insert(data) << endl;
    }
    t -> inorderTraverse();
    return 0;
}
