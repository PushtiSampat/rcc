#include <iostream>

class A
{
    private :
        int a;
        int b;
    public :
        A()
        {
            this -> a = 10; 
            this -> b = 20;
        };

        void readData()
        {
            std :: cout << this -> a << std :: endl; 
            std :: cout << this -> b << std :: endl;
        }
        operator int()
        {
            return 50;
        }
};

int main ()
{
    int num;
    A a;

    num = a;

    a.readData();
    std :: cout << num << std :: endl;
    return 0;
}
