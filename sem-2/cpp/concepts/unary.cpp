#include <iostream>

class A
{
    private : //by default
        int a;
        int b;

    public :
        void readA(void);
    
    A(int num1, int num2)
    {
        this -> a = num1; 
        this -> b = num2;

        std :: cout << this -> a << std :: endl;
        std :: cout << this -> b << std :: endl;
    }

    void operator - ();
    void display (void);

};

void A :: operator - ()
{
    this -> a = -this -> a;
    this -> b = -this -> b;

}

void A :: display (void)
{
    std :: cout << this -> a << std :: endl;
    std :: cout << this -> b << std :: endl;
}

int main ()
{
    A a(10, 20);
    -a;

    a.display();

    return 0;
}
