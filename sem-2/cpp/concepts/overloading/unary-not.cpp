#include <iostream>

using namespace std;

class Integer
{
    private :
        int a;
        int b;
    public :
        Integer()
        {
            this -> a = 10;
            this -> b = 10;
        }

        void operator ! (void)
        {
            this -> a = 0;
            this -> b = 0;
        }

        void display ()
        {
            cout << endl;
            cout << this -> a << endl;
            cout << this -> b << endl;
        }

};


int main ()
{
    Integer i1;

    i1.display();

    !i1;

    cout << endl << "Values set to 0" << endl;

    i1.display();
    
    return 0;
}
