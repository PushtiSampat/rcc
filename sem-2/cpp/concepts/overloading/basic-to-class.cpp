#include <iostream>

class A
{
    private :
        int a;
        int b;

    public :
        A() {
            this -> a = 10;
            this -> b = 20;
        }

        A(int x) {
            this -> a = x;
            this -> b = x;
        }

        void putData(void) {
            std :: cout << this -> a << std :: endl;
            std :: cout << this -> b << std :: endl;
        }
};

int main ()
{
    A a;

    int x = 100;

    a.putData();

    a = x; // means same as => a = A(100);

    a.putData();

    return 0;
}
