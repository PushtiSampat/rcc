#include <iostream>

class A
{
    private : // by default 
        int a;
        int b;
    public :
        A (int num1, int num2)
        {
            this -> a = num1;
            this -> b = num2;
        }

        void display(void);
        friend void operator - (A &);

};

void A :: display (void)
{
    std :: cout << this -> a << std :: endl;
    std :: cout << this -> b << std :: endl;
}

void operator - (A &x)
{
    x.a = -x.a;
    x.b = -x.b;
}

int main ()
{
    A a(50, 60);
    
    a.display();

    -a;

    a.display();

    std :: cout << std :: endl;

    return 0;
}
